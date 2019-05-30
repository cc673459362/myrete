/*

time:2019.5.13
author:xcc

*/

#include "addproduction.h"
/******************************************BETA NET*************************************/




//create or shared a beta memory node in beta net
/*
	this function need arg -->> the betamemorynode needed tobe create or shared 's parent node.
			1.retrieve the parent node's children ,(JOINNODE's children),if there already have a betamemory node,then  now we can shared this node.
			2.if not,then we create a new betamemory node.and insert the node to the parent's children list.

*/
boost::shared_ptr<betamemory> build_or_share_beta_memory_node(boost::shared_ptr<joinnode> &parent){
	std::list<boost::shared_ptr<betamemory> > child=parent->getchildren();
	for(std::list<boost::shared_ptr<betamemory> >::iterator it=child.begin();it!=child.end();it++){
			return *it;
	}
	boost::shared_ptr<betamemory> beta=boost::make_shared<betamemory>();//allocaate a new betamemorynode
	beta->setparent(parent);
	child.push_back(beta);
	parent->setchildren(child); //insert the new betamemorynode into par's children list
	//initialize the memory node to store tokens for any existing matches for the earlier conditions
	return beta;
	
}

//create or share a join node in beta net
/*
	the function also need a parent node as one of args.arg also need am parent node and list of test-at-join node.
	1.retrieve the parent's children node list.if it's join node is same to we wanted.just return it.
	2.if have no child node or not equal to we wanted. create a new node. and insert it to it's am parent an parent's children list
*/
boost::shared_ptr<joinnode> build_or_share_join_node(boost::shared_ptr<betamemory> &parent,boost::shared_ptr<alphamemory> &am,std::list<boost::shared_ptr<testjoinnode> > &test){
	std::list<boost::shared_ptr<joinnode> > child=parent->getchildren();
	for(std::list<boost::shared_ptr<joinnode> >::iterator it=child.begin();it!=child.end();it++){
		if((*it)->getam()==am&&(*it)->gettest()==test)	{
			return *it;
		}
	}
	boost::shared_ptr<joinnode> join=boost::make_shared<joinnode>();
	join->setparent(parent);
	join->setam(am);
	join->settest(test);
	child.push_back(join);
	parent->setchildren(child);//insert to parent;
	std::list<boost::shared_ptr<joinnode> > achild=am->getchildren();
	achild.push_back(join);
	am->setchildren(achild);
	std::cout<<"complete create one joinnode : "<<std::endl;
	std::cout<<"children joinnode size:        "<<std::endl; 
	std::cout<<am->getchildren().size()<<std::endl; 
	std::cout<<""<<std::endl; 
	std::cout<<"-------------------------------------------------"<<std::endl;
	return join;
	


}

//get the testjoinnode list from conditions 
/*
	this function return the list of testjoinnode. it can create the list from conditions.
	1.retrieve the condition's field
	2.if any field variable is occurs in earlier-condtions field f2.
	3.let the i be the largest earlier-condition's number. 
**/

std::list<boost::shared_ptr<testjoinnode> > get_join_tests_from_condition(boost::shared_ptr<condition> &c,std::list<boost::shared_ptr<condition> > &earlierconds){
	std::list<boost::shared_ptr<testjoinnode> > result;
	int count=0;
	count=earlierconds.size();
	int id,attr,value=0;
	for(std::list<boost::shared_ptr<condition> > :: reverse_iterator it=earlierconds.rbegin();it!=earlierconds.rend();it++){//note: the iterator of list if  bidirectional iterator,cannot using "operator-" to count the number.so we need a counter num.
	
	if(c->getid()==(*it)->getid()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"identifier");
		result.push_back(re);
		id=1;
	}
	if(c->getid()==(*it)->getattr()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"attribute");
		result.push_back(re);
		id=1;
	}
	if(c->getid()==(*it)->getvalue()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"value");
		result.push_back(re);
		id=1;
	}
	if(c->getattr()==(*it)->getid()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"identifier");
		result.push_back(re);

		attr=1;
	}
	if(c->getattr()==(*it)->getattr()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"attribute");
		result.push_back(re);
		attr=1;
	}
	if(c->getattr()==(*it)->getvalue()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"value");
		result.push_back(re);
		attr=1;
	}
	if(c->getvalue()==(*it)->getid()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"identifier");
		result.push_back(re);
		value=1;
	}
	if(c->getvalue()==(*it)->getattr()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"attribute");
		result.push_back(re);
		value=1;
	}
	if(c->getvalue()==(*it)->getvalue()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"value");
		result.push_back(re);
		value=1;
	}
	count--;
	
	}
	return result;
	
}

/*************************************END BETA NET****************************/

/***********************************ALPHA NET***************************************/
/**
	using in the function: build_or_shared_alphamemory


**/
boost::shared_ptr<alphanode> build_or_share_constant_test_node(const boost::shared_ptr<alphanode> &parent,const std::string field,const std::string symbol){
	std::list<boost::shared_ptr<alphanode> > children=parent->getalp();
	for(std::list<boost::shared_ptr<alphanode> >::iterator it=children.begin();it!=children.end();it++){
		if((*it)->gettestfield()==field&&(*it)->getminsymbol()==mygetfirst(symbol)&&(*it)->getmaxsymbol()==mygetsecond(symbol)){
			return *it;		
		}
	}
	//couldn't find a node to share,so build a new one
	boost::shared_ptr<alphanode> result=boost::make_shared<alphanode>();
	result->settestfield(field);
	result->setminsymbol(mygetfirst(symbol));
	result->setmaxsymbol(mygetsecond(symbol));
	children.push_back(result);
	parent->setalp(children);
	return result;
		
}
/**
	build alpha net from root node and the condition

**/
boost::shared_ptr<alphamemory> build_or_share_alphamemory(boost::shared_ptr<condition> &c,boost::shared_ptr<alphanode> &root){
	boost::shared_ptr<alphanode> currentnode=root;
	std::string id=c->getid();//first field
	currentnode=build_or_share_constant_test_node(currentnode,"identifier",id);
	std::string attr=c->getattr();
	currentnode=build_or_share_constant_test_node(currentnode,"attribute",attr);
	std::string value=c->getvalue();
	currentnode=build_or_share_constant_test_node(currentnode,"value",value);
	if ( currentnode->getalphamemory()!=NULL){
		return currentnode->getalphamemory();
	}
	boost::shared_ptr<alphamemory> am=boost::make_shared<alphamemory>();
	currentnode->setalphamemory(am);
	std::cout<<"complete create one alphamemory from condition : "<<std::endl;
	std::cout<<c->getid()<<std::endl; 
	std::cout<<c->getattr()<<std::endl; 
	std::cout<<c->getvalue()<<std::endl; 
	std::cout<<"-------------------------------------------------"<<std::endl; 
	return am;
	
}
/**********************************END OF ALPHA NET***********************************/

/*****************************************READ FILE*************************************/
//create list of conditions
/*
	read from rule.text and create the conditions.

*/

std::list<boost::shared_ptr<condition> > createconditions(){
	std::list<boost::shared_ptr<condition> >	result;
	std::ifstream in;
	std::string s;
	in.open("../rule/rule.txt",std::ios::in);
	if(in.is_open()){
		while(!in.eof()){
			getline(in,s);
			if(s[0]=='r'&&s[1]=='u'&&s[2]=='l'&&s[3]=='e'){
				continue;
			}	
			else if(s=="LHS:"){
				continue;
			}
			else if(s=="RHS:"){
				break;
			}
			else{
				std::istringstream ss(s);
				std::string id;
				std::string attr;
				std::string value;
				ss>>id;
				std::cout<<id<<" ";
				ss>>attr;
				std::cout<<attr<<" ";
				ss>>value;
				std::cout<<value<<std::endl;
				boost::shared_ptr<condition> cond=boost::make_shared<condition>(id,attr,value);
				result.push_back(cond);
			}
		}
	}
	return result;
	

}

/*
	create RHS vector

*/
std::vector<std::pair<std::string,std::string> > createrhs(){
	std::vector<std::pair<std::string,std::string> >	result;
	std::ifstream in;
	std::string s;
	std::string num;
	int yes=0;
	in.open("../rule/rule.txt",std::ios::in);
	if(in.is_open()){
		while(!in.eof()){
			getline(in,s);
			if(s[0]=='r'&&s[1]=='u'&&s[2]=='l'&&s[3]=='e'){
				int n=s.size();
				std::string sb=s.substr(5,n-5);
				num=sb;
				std::cout<<"*******************"<<std::endl;
				std::cout<<num<<std::endl;
			}	
			else if(s!="RHS:"&&yes==0){
				continue;
			}
			else if(s=="RHS:"){
				yes=1;				
				continue;
			}
			else {
				result.push_back(std::make_pair(s,num));
				yes=0;
			}
		}
	}
	return result;
}

/*
	get first half symbol from symbol
*/
std::string mygetfirst(const std::string &symbol){
	std::string minsymbol;	
	int n=symbol.size();
	for(int i=0;i<n;i++){
		if(symbol[i]==','){
			minsymbol=symbol.substr(0,i);
			return minsymbol;
		}
	}
	minsymbol=symbol;
	return minsymbol;
}

/*
	get second half symbol from symbol
*/
std::string mygetsecond(const std::string &symbol){
	std::string minsymbol;	
	int n=symbol.size();
	for(int i=0;i<n;i++){
		if(symbol[i]==','){
			minsymbol=symbol.substr(i+1,n-i);
			return minsymbol;
		}
	}
	minsymbol=symbol;
	return minsymbol;
}
/***********************************END OF READ FILE*********************************/





/*******************************CREATE FULL NET FROM CONDITIONS************************/
bool add_production(std::list<boost::shared_ptr<condition> > &lhs,const std::string &num, boost::shared_ptr<betamemory> &dummynode,boost::shared_ptr<alphanode> &root){
	boost::shared_ptr<betamemory> currentnode=dummynode;
	std::list<boost::shared_ptr<condition> > earlierconds;
	std::list<boost::shared_ptr<condition> >::iterator it=lhs.begin();
	std::list<boost::shared_ptr<testjoinnode> > tests=get_join_tests_from_condition(*it,earlierconds);
	boost::shared_ptr<alphamemory> am=build_or_share_alphamemory(*it,root);
	boost::shared_ptr<joinnode> currentjoinnode=build_or_share_join_node(currentnode,am,tests);
	it++;
	for(it;it!=lhs.end();it++){
		//get the beta memory node Mi
		currentnode=build_or_share_beta_memory_node(currentjoinnode);
		//get the join node Ji for condition ci
		it--;
		earlierconds.push_back(*it);
		it++;
		tests=get_join_tests_from_condition(*it,earlierconds);
		am=build_or_share_alphamemory(*it,root);
		currentjoinnode=build_or_share_join_node(currentnode,am,tests);
	}
	boost::shared_ptr<terminalnode > terminal=boost::make_shared<terminalnode>(num);//num="0" token=NULL
	currentjoinnode->setterminal(terminal);
	std::cout<<currentjoinnode->getterminal()->getnum()<<std::endl;
	

	
}

/**********************END OF CREATE FULL NET FROM CONDITIONS*************************/
