/*
2019.5.16
author:xcc

*/
#include "addproduction.h"
#include<string>
#include<iostream>
#include<list>
#include<vector>
std::list<boost::shared_ptr<rule> > rules=createrules();
int main(){
	//create rules
	
	std::cout<<"rules size : "<<rules.size()<<std::endl;
	//create dummynode
	boost::shared_ptr<betamemory> dummynode=boost::make_shared<betamemory>();
	//create root node
	boost::shared_ptr<alphanode> root=boost::make_shared<alphanode>();
	if(root->getalphamemory()==NULL){
		std::cout<<"root's am is null"<<std::endl;
	}
	root->settestfield("NO-TEST");
	for(std::list<boost::shared_ptr<rule> >::iterator it=rules.begin();it!=rules.end();it++){
		add_production(*it,dummynode,root);
		std::cout<<"#############complete compiler "<<(*it)->getname()<<" net! ##################"<<std::endl;
	}
	
	std::cout<<"complete compiler the net!"<<std::endl;
	boost::shared_ptr<workingmemory> wm=boost::make_shared<workingmemory>(root);
	/************* insert into wm*****************
	boost::shared_ptr<myWME> t=boost::make_shared<myWME>("temprature","=","32");
	boost::shared_ptr<myWME> w=boost::make_shared<myWME>("windows","=","0");;
	boost::shared_ptr<myWME> r=boost::make_shared<myWME>("rain","=","0");;
	
	wm.addmyWME(t);
	wm.addmyWME(w);
	wm.addmyWME(r);
	********************************************/
	std::ifstream in;
	in.open("../data/data",std::ios::in);
	while(1){
		
		getdataintowm(wm,in);
	}
	in.close();
		
}
