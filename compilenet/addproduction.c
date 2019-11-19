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
			std::cout<<"-------------------------------------------------"<<std::endl; 
			std::cout<<"complete share one joinnode : "<<std::endl;
			std::cout<<"children joinnode size:        "<<std::endl; 
			std::cout<<am->getchildren().size()<<std::endl; 
			std::cout<<""<<std::endl; 
			std::cout<<"-------------------------------------------------"<<std::endl;
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
	std::cout<<"-------------------------------------------------"<<std::endl; 
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
	int id=0;
	int attr=0;
	int value=0;
#ifdef ORIGIN
	int arg4=0;
	int arg5=0;
	int arg6=0;
	int arg7=0;
	int arg8=0;
#endif
	std::cout<<"@@@@@@@@@@@@@@ now condition's id "<<c->getid()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now condition's attr "<<c->getattr()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now condition's value "<<c->getvalue()<<std::endl;
#ifdef ORIGIN
	std::cout<<"@@@@@@@@@@@@@@ now condition's arg4 "<<c->getarg4()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now condition's arg5 "<<c->getarg5()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now condition's arg6 "<<c->getarg6()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now condition's arg7 "<<c->getarg7()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now condition's arg8 "<<c->getarg8()<<std::endl;
#endif
	for(std::list<boost::shared_ptr<condition> > :: reverse_iterator it=earlierconds.rbegin();it!=earlierconds.rend();it++){//note: the iterator of list if  bidirectional iterator,cannot using "operator-" to count the number.so we need a counter num.
	
	std::cout<<"@@@@@@@@@@@@@@ now earliercond id "<<(*it)->getid()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now earliercond attr "<<(*it)->getattr()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now earliercond value "<<(*it)->getvalue()<<std::endl;
#ifdef ORIGIN
	std::cout<<"@@@@@@@@@@@@@@ now earliercond arg4 "<<(*it)->getarg4()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now earliercond arg5 "<<(*it)->getarg5()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now earliercond arg6 "<<(*it)->getarg6()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now earliercond arg7 "<<(*it)->getarg7()<<std::endl;
	std::cout<<"@@@@@@@@@@@@@@ now earliercond arg8 "<<(*it)->getarg8()<<std::endl;
#endif
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
#ifdef ORIGIN
	if(c->getid()==(*it)->getarg4()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"arg4");
		result.push_back(re);
		id=1;
	}
	if(c->getid()==(*it)->getarg5()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"arg5");
		result.push_back(re);
		id=1;
	}
	if(c->getid()==(*it)->getarg6()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"arg6");
		result.push_back(re);
		id=1;
	}
	if(c->getid()==(*it)->getarg7()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"arg7");
		result.push_back(re);
		id=1;
	}
	if(c->getid()==(*it)->getarg8()&&id==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("identifier",count,"arg8");
		result.push_back(re);
		id=1;
	}
#endif
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
#ifdef ORIGIN
	if(c->getattr()==(*it)->getarg4()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"arg4");
		result.push_back(re);
		attr=1;
	}
	if(c->getattr()==(*it)->getarg5()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"arg5");
		result.push_back(re);
		attr=1;
	}
	if(c->getattr()==(*it)->getarg6()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"arg6");
		result.push_back(re);
		attr=1;
	}
	if(c->getattr()==(*it)->getarg7()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"arg7");
		result.push_back(re);
		attr=1;
	}
	if(c->getattr()==(*it)->getarg8()&&attr==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("attribute",count,"arg8");
		result.push_back(re);
		attr=1;
	}
#endif
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
#ifdef ORIGIN
	if(c->getvalue()==(*it)->getarg4()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"arg4");
		result.push_back(re);
		value=1;
	}
	if(c->getvalue()==(*it)->getarg5()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"arg5");
		result.push_back(re);
		value=1;
	}
	if(c->getvalue()==(*it)->getarg6()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"arg6");
		result.push_back(re);
		value=1;
	}
	if(c->getvalue()==(*it)->getarg7()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"arg7");
		result.push_back(re);
		value=1;
	}
	if(c->getvalue()==(*it)->getarg8()&&value==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("value",count,"arg8");
		result.push_back(re);
		value=1;
	}
#endif
#ifdef ORIGIN
	if(c->getarg4()==(*it)->getid()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"identifier");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getattr()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"attribute");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getvalue()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"value");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getarg4()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"arg4");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getarg5()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"arg5");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getarg6()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"arg6");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getarg7()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"arg7");
		result.push_back(re);
		arg4=1;
	}
	if(c->getarg4()==(*it)->getarg8()&&arg4==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg4",count,"arg8");
		result.push_back(re);
		arg4=1;
	}
//-------------------------------------------------------------------------------------------------------------------arg5
	if(c->getarg5()==(*it)->getid()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"identifier");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getattr()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"attribute");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getvalue()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"value");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getarg4()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"arg4");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getarg5()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"arg5");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getarg6()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"arg6");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getarg7()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"arg7");
		result.push_back(re);
		arg5=1;
	}
	if(c->getarg5()==(*it)->getarg8()&&arg5==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg5",count,"arg8");
		result.push_back(re);
		arg5=1;
	}
//--------------------------------------------------------------------------------------------------------------------arg6
	if(c->getarg6()==(*it)->getid()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"identifier");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getattr()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"attribute");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getvalue()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"value");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getarg4()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"arg4");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getarg5()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"arg5");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getarg6()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"arg6");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getarg7()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"arg7");
		result.push_back(re);
		arg6=1;
	}
	if(c->getarg6()==(*it)->getarg8()&&arg6==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg6",count,"arg8");
		result.push_back(re);
		arg6=1;
	}
//-----------------------------------------------------------------------------------------------------------arg7
	if(c->getarg7()==(*it)->getid()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"identifier");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getattr()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"attribute");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getvalue()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"value");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getarg4()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"arg4");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getarg5()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"arg5");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getarg6()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"arg6");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getarg7()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"arg7");
		result.push_back(re);
		arg7=1;
	}
	if(c->getarg7()==(*it)->getarg8()&&arg7==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg7",count,"arg8");
		result.push_back(re);
		arg7=1;
	}
//-----------------------------------------------------------------------------------------------------------arg8
	if(c->getarg8()==(*it)->getid()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"identifier");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getattr()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"attribute");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getvalue()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"value");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getarg4()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"arg4");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getarg5()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"arg5");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getarg6()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"arg6");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getarg7()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"arg7");
		result.push_back(re);
		arg8=1;
	}
	if(c->getarg8()==(*it)->getarg8()&&arg8==0){
		boost::shared_ptr<testjoinnode> re= boost::make_shared<testjoinnode>("arg8",count,"arg8");
		result.push_back(re);
		arg8=1;
	}
#endif
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
			std::cout<<"share constant test node!!"<<std::endl;
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
#ifdef ORIGIN
	std::string arg4=c->getarg4();//arg4
	currentnode=build_or_share_constant_test_node(currentnode,"arg4",arg4);
	std::string arg5=c->getarg5();//arg5
	currentnode=build_or_share_constant_test_node(currentnode,"arg5",arg5);
	std::string arg6=c->getarg6();//arg6
	currentnode=build_or_share_constant_test_node(currentnode,"arg6",arg6);
	std::string arg7=c->getarg7();//arg7
	currentnode=build_or_share_constant_test_node(currentnode,"arg7",arg7);
	std::string arg8=c->getarg8();//arg8
	currentnode=build_or_share_constant_test_node(currentnode,"arg8",arg8);
#endif
	if ( currentnode->getalphamemory()!=NULL){
		std::cout<<"-------------------------------------------------"<<std::endl; 
		std::cout<<"complete share one alphamemory from condition : "<<std::endl;
		std::cout<<c->getid()<<std::endl; 
		std::cout<<c->getattr()<<std::endl; 
		std::cout<<c->getvalue()<<std::endl; 
#ifdef ORIGIN
		std::cout<<c->getarg4()<<std::endl;
		std::cout<<c->getarg5()<<std::endl;
		std::cout<<c->getarg6()<<std::endl;
		std::cout<<c->getarg7()<<std::endl;
		std::cout<<c->getarg8()<<std::endl;
#endif
		std::cout<<"-------------------------------------------------"<<std::endl; 
		return currentnode->getalphamemory();
	}
	boost::shared_ptr<alphamemory> am=boost::make_shared<alphamemory>();
	currentnode->setalphamemory(am);
	std::cout<<"-------------------------------------------------"<<std::endl; 
	std::cout<<"complete create one alphamemory from condition : "<<std::endl;
	std::cout<<c->getid()<<std::endl; 
	std::cout<<c->getattr()<<std::endl; 
	std::cout<<c->getvalue()<<std::endl; 
#ifdef ORIGIN
	std::cout<<c->getarg4()<<std::endl;
	std::cout<<c->getarg5()<<std::endl;
	std::cout<<c->getarg6()<<std::endl;
	std::cout<<c->getarg7()<<std::endl;
	std::cout<<c->getarg8()<<std::endl;
#endif
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
#ifdef ORIGIN
				std::string arg4;
				std::string arg5;
				std::string arg6;
				std::string arg7;
				std::string arg8;
#endif
				ss>>id;
				std::cout<<id<<" ";
				ss>>attr;
				std::cout<<attr<<" ";
				ss>>value;
#ifndef ORIGIN
				std::cout<<value<<std::endl;
#endif
#ifdef ORIGIN
				std::cout<<value<<" ";
				ss>>arg4;
				std::cout<<arg4<<" ";
				ss>>arg5;
				std::cout<<arg5<<" ";
				ss>>arg6;
				std::cout<<arg6<<" ";
				ss>>arg7;
				std::cout<<arg7<<" ";
				ss>>arg8;
				std::cout<<arg8<<std::endl;
#endif
#ifndef ORIGIN
				boost::shared_ptr<condition> cond=boost::make_shared<condition>(id,attr,value);
#endif
#ifdef ORIGIN
				boost::shared_ptr<condition> cond=boost::make_shared<condition>(id,attr,value,arg4,arg5,arg6,arg7,arg8);
#endif
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
	create rules from rule.txt
*/
std::list<boost::shared_ptr<rule> > createrules(){
	std::list<boost::shared_ptr<rule> > result;
	std::list<boost::shared_ptr<condition> > conds;
	std::string name;
	std::string rhs;
	std::ifstream in;
	std::string s;
	int isrhs=0;
	in.open("../rule/rule.txt",std::ios::in);
	if(in.is_open()){
		while(!in.eof()){
			getline(in,s);
			if(s[0]=='r'&&s[1]=='u'&&s[2]=='l'&&s[3]=='e'){
				std::string a;
				std::istringstream ss(s);
				ss>>a;
				ss>>name;
				std::cout<<"****rule name is: ***** "<<name<<std::endl;
			}
			else if(s[0] == 'L'&&s[1]=='H'){				
				isrhs=0;
				std::cout<<"****next is LHS: "<<std::endl;
			}
			else if(s[0] =='R'&&s[1]=='H'){
				isrhs=1;
				std::cout<<"****next is RHS: "<<std::endl;
			}
			else if(s[1]!='H'&&isrhs==0){
				std::istringstream ss(s);
				std::string id;
				std::string attr;
				std::string value;
#ifdef ORIGIN
				std::string arg4;
				std::string arg5;
				std::string arg6;
				std::string arg7;
				std::string arg8;
#endif
				ss>>id;
				std::cout<<"LHS ID : "<<id<<" ";
				ss>>attr;
				std::cout<<"LHS ATTR : "<<attr<<" ";
				ss>>value;
#ifndef ORIGIN
				std::cout<<"LHS VALUE : "<<value<<std::endl;
#endif
#ifdef ORIGIN
				std::cout<<"LHS VALUE : "<<value<<" ";
				ss>>arg4;
				std::cout<<"LHS ARG4 : "<<arg4<<" ";
				ss>>arg5;
				std::cout<<"LHS ARG5 : "<<arg5<<" ";
				ss>>arg6;
				std::cout<<"LHS ARG6 : "<<arg6<<" ";
				ss>>arg7;
				std::cout<<"LHS ARG7 : "<<arg7<<" ";
				ss>>arg8;
				std::cout<<"LHS ARG8 : "<<arg8<<std::endl;
				
#endif
#ifndef ORIGIN
				boost::shared_ptr<condition> cond=boost::make_shared<condition>(id,attr,value);
#endif
#ifdef ORIGIN
				boost::shared_ptr<condition> cond=boost::make_shared<condition>(id,attr,value,arg4,arg5,arg6,arg7,arg8);
#endif
				conds.push_back(cond);
			}
			else if(s[1]!='H'&&s[0]!='e'&&isrhs==1){
				rhs=s;
				std::cout<<"RHS : "<<rhs<<std::endl;
			}
			else if(s[0]=='e'){
				boost::shared_ptr<rule> re=boost::make_shared<rule>();
				re->setname(name);
				re->setconditions(conds);
				re->setrhs(rhs);
				result.push_back(re);
				conds.clear();
				
			}
			else if(s==""){
				continue;
			}
			
		}	
	}

	return result;


}

/*
	get data from data file and form to WME inserted into wm.
*/

void getdataintowm(boost::shared_ptr<workingmemory> &wm,std::ifstream &in,int &timesum){
	boost::shared_ptr<myWME> result;
	std::string s;
	std::string identifier;
	std::string attribute;
	std::string value;
	std::string arg4;
	std::string arg5;
	std::string arg6;
	std::string arg7;
	std::string arg8;	
	if(in.is_open()){
		while(!in.eof()){
			getline(in,s);   //   data file should not have a empty line after all.  And getline will read a empty line after all and need to be delete.
			if(s==""){
				break;	   //  break??????????????????????/continiue???????????????
			}
			std::istringstream ss(s);
			ss>>identifier;
			std::cout<<"data file identifier: "<<identifier<<std::endl;
			ss>>attribute;
			std::cout<<"data file attribute : "<<attribute<<std::endl;
			ss>>value;
			std::cout<<"data file value     : "<<value<<std::endl;
#ifdef ORIGIN
			ss>>arg4;
			std::cout<<"data file arg4      : "<<arg4<<std::endl;
			ss>>arg5;
			std::cout<<"data file arg5      : "<<arg5<<std::endl;
			ss>>arg6;
			std::cout<<"data file arg6      : "<<arg6<<std::endl;
			ss>>arg7;
			std::cout<<"data file arg7      : "<<arg7<<std::endl;
			ss>>arg8; 
			std::cout<<"data file arg8      : "<<arg8<<std::endl;
#endif
#ifndef ORIGIN
			result=boost::make_shared<myWME>(identifier,attribute,value);
#endif
#ifdef ORIGIN
			result=boost::make_shared<myWME>(identifier,attribute,value,arg4,arg5,arg6,arg7,arg8);
#endif
			std::cout<<"add a WME into wm "<<std::endl;
			clock_t begin=clock();
			wm->addmyWME(result);
			clock_t end=clock();
			timesum+=end-begin;
			//break;
		}
	}
	
	
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
bool add_production(const boost::shared_ptr<rule> &rule,/*std::list<boost::shared_ptr<condition> > &lhs,const std::string &num,*/ boost::shared_ptr<betamemory> &dummynode,boost::shared_ptr<alphanode> &root,std::vector<boost::shared_ptr<alphamemory> > &indexvector){
	boost::shared_ptr<betamemory> currentnode=dummynode;
	std::list<boost::shared_ptr<condition> > earlierconds;
	std::list<boost::shared_ptr<condition> > lhs=rule->getconditions();
	std::string num=rule->getname();
	std::list<boost::shared_ptr<condition> >::iterator it=lhs.begin();
	std::list<boost::shared_ptr<testjoinnode> > tests=get_join_tests_from_condition(*it,earlierconds);
	/** DEBUG COUT***/
	int count =1;
	if(tests.size()!=0){
		for(std::list<boost::shared_ptr<testjoinnode> >::iterator it1=tests.begin();it1!=tests.end();it1++){
			std::cout<<"test "<<count<<" arg1: "<<(*it1)->getarg1()<<std::endl;
			std::cout<<"test "<<count<<" arg2: "<<(*it1)->getarg2()<<std::endl;
			std::cout<<"test "<<count<<" number of arg2: "<<(*it1)->getnumberofarg2()<<std::endl;
		}
	}else{
		std::cout<<"test "<<count<<" is null"<<std::endl;
	}
	count++;
	/** DEBUG COUT***/
	boost::shared_ptr<alphamemory> am=build_or_share_alphamemory(*it,root);
	indexvector.push_back(am); //collect the am
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
		/** DEBUG COUT***/
	
		if(tests.size()!=0){
			for(std::list<boost::shared_ptr<testjoinnode> >::iterator it1=tests.begin();it1!=tests.end();it1++){
				std::cout<<"test "<<count<<" arg1: "<<(*it1)->getarg1()<<std::endl;
				std::cout<<"test "<<count<<" arg2: "<<(*it1)->getarg2()<<std::endl;
				std::cout<<"test "<<count<<" number of arg2: "<<(*it1)->getnumberofarg2()<<std::endl;
			}
		}else{
			std::cout<<"test "<<count<<"is null"<<std::endl;
		}
		count++;
		/** DEBUG COUT***/
		am=build_or_share_alphamemory(*it,root);
		indexvector.push_back(am);  //collect the am
		currentjoinnode=build_or_share_join_node(currentnode,am,tests);
	}
	boost::shared_ptr<terminalnode > terminal=boost::make_shared<terminalnode>(num);//rule
	currentjoinnode->setterminal(terminal);
	std::cout<<currentjoinnode->getterminal()->getnum()<<std::endl;
	
}

/**********************END OF CREATE FULL NET FROM CONDITIONS*************************/
