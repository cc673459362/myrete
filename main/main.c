/*
2019.5.16
author:xcc

*/
#include "addproduction.h"
#include<string>
#include<iostream>
#include<list>
#include<vector>
#include<ctime>
clock_t readrule_start=clock();
std::list<boost::shared_ptr<rule> > rules=createrules();
int main(){
	//create rules
	clock_t readrule_end=clock();
	std::cout<<"read rules from file and create list of rule spend :"<<readrule_end-readrule_start<<"(ns) "<<std::endl;
	std::cout<<"rules size : "<<rules.size()<<std::endl;
	clock_t compile_start=clock();
	//create dummynode
	boost::shared_ptr<betamemory> dummynode=boost::make_shared<betamemory>();
	//create root node
	boost::shared_ptr<alphanode> root=boost::make_shared<alphanode>();
	#ifdef DEBUG
	if(root->getalphamemory()==NULL){
		std::cout<<"root's am is null"<<std::endl;
	}
	#endif
	root->settestfield("NO-TEST");
	std::vector<boost::shared_ptr<alphamemory> > indexvector;
	for(std::list<boost::shared_ptr<rule> >::iterator it=rules.begin();it!=rules.end();it++){
		add_production(*it,dummynode,root,indexvector);
		std::cout<<"#############complete compiler "<<(*it)->getname()<<" net! ##################"<<std::endl;
	}
#ifdef BTREE
	for(std::vector<boost::shared_ptr<alphamemory> >::iterator it=indexvector.begin();it!=indexvector.end();it++){
		(*it)->createbtree(5);  //degree=5
	}
#endif
	clock_t compile_end=clock();
	std::cout<<"complete compiler the net!"<<std::endl;
	std::cout<<"compile the net spend: "<<compile_end-compile_start<<"(ns) "<<std::endl;
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
	int timesum=0;
	while(!in.eof()){
		getdataintowm(wm,in,timesum);
	}
	std::cout<<"time is: "<<timesum<<std::endl;
	in.close();
		
}
