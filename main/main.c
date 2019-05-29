/*
2019.5.16
author:xcc

*/
#include "addproduction.h"
#include<string>
#include<iostream>
#include<list>

int main(){
	std::list<boost::shared_ptr<condition> > conditions=createconditions();
	boost::shared_ptr<betamemory> dummynode=boost::make_shared<betamemory>();
	boost::shared_ptr<alphanode> root=boost::make_shared<alphanode>();
	root->settestfield("NO-TEST");
	add_production(conditions,dummynode,root);
	std::cout<<"complete compiler the net!"<<std::endl;
	
		
}
