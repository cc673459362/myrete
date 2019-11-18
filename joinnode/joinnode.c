/*

time:2019.5.9
author:xcc

*/

#include "joinnode.h"
#include "alphamemory.h"
#include "betamemory.h"
/********      testjoinnode     ********/

//construction
testjoinnode::testjoinnode(const std::string &field_of_arg1,const int &condition_number_of_arg2,const std::string &field_of_arg2):_field_of_arg1(field_of_arg1),_condition_number_of_arg2(condition_number_of_arg2),_field_of_arg2(field_of_arg2){
	

}

//default construction
testjoinnode::testjoinnode(){

}

//destroy
testjoinnode::~testjoinnode(){

}

//get the arg1
std::string testjoinnode::getarg1(){
	return _field_of_arg1;
}

//get the arg2
std::string testjoinnode::getarg2(){
	return _field_of_arg2;
}

//get the number of arg2 in condition
int testjoinnode::getnumberofarg2(){
	return _condition_number_of_arg2;
}

//set the arg1
bool testjoinnode::setarg1(const std::string &arg1){
	_field_of_arg1=arg1;
	return true;
}

//set the arg2
bool testjoinnode::setarg2(const std::string &arg2){
	_field_of_arg2=arg2;
	return true;
}

//set the number of arg2 in condition
bool testjoinnode::setnumberofarg2(const int &n){
	_condition_number_of_arg2=n;
	return true;
}

/********     end of testjoinnode     ********/


/********        joinnode             ********/

//construction
joinnode::joinnode(const std::list<boost::shared_ptr<betamemory> > &children,const boost::shared_ptr<betamemory> &parent,const boost::shared_ptr<terminalnode> &terminal,const boost::shared_ptr<alphamemory>   &am,const std::list<boost::shared_ptr<testjoinnode> > &test):_children(children),_parent(parent),_terminal(terminal),_am(am),_test(test){
	
}

//default construction
joinnode::joinnode(){

}

//destroy
joinnode::~joinnode(){

}

//get parent
boost::shared_ptr<betamemory> joinnode::getparent(){
	return _parent;
}

//set parent
bool joinnode::setparent(boost::shared_ptr<betamemory> &parent){
	_parent=parent;
	return true;
}

//get children
std::list<boost::shared_ptr<betamemory> > joinnode::getchildren(){
	return _children;
}

//set children
bool joinnode::setchildren(std::list<boost::shared_ptr<betamemory> > &children){
	_children=children;
	return true;
}

//get terminal
boost::shared_ptr<terminalnode> joinnode::getterminal(){
	return _terminal;
}

//set terminal
bool joinnode::setterminal(boost::shared_ptr<terminalnode> &terminal){
	_terminal=terminal;	
	return true;
}

//get the alphamemory node
boost::shared_ptr<alphamemory> joinnode::getam(){
	return _am;
}



//set the parent am node
bool joinnode::setam(const boost::shared_ptr<alphamemory> &am){
	_am=am;
	return true;
}

//get the test list
std::list<boost::shared_ptr<testjoinnode> > joinnode::gettest(){
	return _test;
}

//set the test list
bool joinnode::settest(const std::list<boost::shared_ptr<testjoinnode> > &test){
	_test=test;
	return true;
}

// join node's combile test
/*
	the arg1 test means the combine condition of this join node
	the arg2 t    means the parent node's token
	the arg3 w    means the alpha memory's new WME which active the right activation
*/
bool performjoinnode(std::list<boost::shared_ptr<testjoinnode> > &test,const boost::shared_ptr<token> &t,const boost::shared_ptr<myWME> &w){
	if(t==NULL)	std::cout<<"token is NULL "<<std::endl;
	std::list<boost::shared_ptr<testjoinnode> >::iterator it=test.begin();
	std::cout<<"test list size: "<<test.size()<<std::endl;
	for(it;it!=test.end();it++){
		std::cout<<"<---into testjoin--->    "<<std::endl;
		std::string arg1=(*it)->getarg1();
		if(arg1=="identifier"){
			arg1=w->getid();
		}
		else if(arg1=="attribute"){
			arg1=w->getattr();
		}
		else if(arg1=="value"){
			arg1=w->getvalue();
		}//arg1
#ifdef ORIGIN
		else if(arg1=="arg4"){
			arg1=w->getarg4();
		}
		else if(arg1=="arg5"){
			arg1=w->getarg5();
		}
		else if(arg1=="arg6"){
			arg1=w->getarg6();
		}
		else if(arg1=="arg7"){
			arg1=w->getarg7();
		}
		else if(arg1=="arg8"){
			arg1=w->getarg8();
		}
		
#endif
		int n=(*it)->getnumberofarg2();
		boost::shared_ptr<myWME> w2;
		//w2.reset();// set the w2==NULL;
		
		if(t==NULL){	
			std::cout<<"token is empty perform false!!!!!!!!"<<std::endl;
			return false;
		}
		boost::shared_ptr<token> tt=t;
		while(tt!=NULL){
			
			if(tt->getnum()==n){
				w2=tt->getmyWME();
				break;
			}
			tt=tt->getfront();
		}//w2
		std::string arg2=(*it)->getarg2();
		if(w2==NULL) return false;
		if(w2!=NULL){
			if(arg2=="identifier"){
				arg2=w2->getid();
			}
			else if(arg2=="attribute"){
				arg2=w2->getattr();
			}
			else if(arg2=="value"){
				arg2=w2->getvalue();
			}//arg2
#ifdef ORIGIN
			else if(arg2=="arg4"){
				arg2=w2->getarg4();
			}
			else if(arg2=="arg5"){
				arg2=w2->getarg5();
			}
			else if(arg2=="arg6"){
				arg2=w2->getarg6();
			}
			else if(arg2=="arg7"){
				arg2=w2->getarg7();
			}
			else if(arg2=="arg8"){
				arg2=w2->getarg8();
			}			
#endif
		}
		if(arg1!=arg2)  {
			return false;
		}
		
	}
	return true;
}

//the joinnode was right_activation by it's _am->addwme(w)
/*
	the step to finish the right activation is:1. retireve the parent's token list,if some of token and the w is test true, then 2
					    	   2. left activation the betamemory,also means pass the new token to the children node(if there are terminal node after joinnode.also need to add token to the terminalnode)
*/
bool joinnode::join_node_right_activation(boost::shared_ptr<myWME> &w){
	boost::shared_ptr<betamemory> parent=this->getparent();
	std::list<boost::shared_ptr<token> > partoken=parent->gettoken();
	int n=partoken.size();
	if(n!=0){
	std::cout<<"-------------------------------------"<<std::endl;
	std::cout<<"jonnode's parent token not empty       "<<std::endl;
	std::cout<<"-------------------------------------"<<std::endl;
	for(std::list<boost::shared_ptr<token> >::iterator it=partoken.begin();it!=partoken.end();it++){
		if(performjoinnode(this->_test,*it,w)){   //setp 1
			if(this->getterminal()!=NULL){//if has terminal node
				std::cout<<"right insert into terminalnode :"<<this->getterminal()->getnum()<<std::endl;
				this->getterminal()->addtoken(*it,w);
			}
			for(std::list<boost::shared_ptr<betamemory> >::iterator it2=_children.begin();it2!=_children.end();it2++ ){
				std::cout<<"-------------------------------------"<<std::endl;
				std::cout<<"joinnode right activation betamemory left       "<<std::endl;
				std::cout<<"-------------------------------------"<<std::endl;
				(*it2)->beta_memory_left_activation(*it,w); //step 2
			}		
		}
		else{
			std::cout<<"joinnode match failed!   "<<std::endl;
		}
	}
	}
	else{	
		std::cout<<"-------------------------------------"<<std::endl;
		std::cout<<"jonnode's parent token is empty       "<<std::endl;
		std::cout<<"-------------------------------------"<<std::endl;
		std::list<boost::shared_ptr<token> >::iterator it=partoken.begin();
		if(*it==NULL)std::cout<<"it is NULL  "<<std::endl;
		if(performjoinnode(this->_test,*it,w)){   //setp 1
			if(this->getterminal()!=NULL){//if has terminal node
				//std::cout<<"thathathathahthathahtaht"<<std::endl;
				std::cout<<"right insert into terminalnode :"<<this->getterminal()->getnum()<<std::endl;
				this->getterminal()->addtoken(*it,w);
			}
			for(std::list<boost::shared_ptr<betamemory> >::iterator it2=_children.begin();it2!=_children.end();it2++ ){
				std::cout<<"-------------------------------------"<<std::endl;
				std::cout<<"joinnode right activation betamemory left  (0)     "<<std::endl;
				std::cout<<"-------------------------------------"<<std::endl;
				(*it2)->beta_memory_left_activation(*it,w); //step 2
			}		
		}
		else{
			std::cout<<"joinnode match failed!(0)   "<<std::endl;
		}
	}
	return true;
}

//the joinnode was left activation by it's parent->left_betamemroy_activation
bool joinnode::join_node_left_activation(boost::shared_ptr<token> &t){
	boost::shared_ptr<alphamemory> am=this->getam();
	std::list<boost::shared_ptr<myWME> > wmes=am->getam();
	for(std::list<boost::shared_ptr<myWME> > ::iterator it=wmes.begin();it!=wmes.end();it++){
		if(performjoinnode(this->_test,t,*it)){
			if(this->getterminal()!=NULL){//if has terminal node
				std::cout<<"left insert into terminalnode :"<<this->getterminal()->getnum()<<std::endl;
				this->getterminal()->addtoken(t,*it);
			}
			for(std::list<boost::shared_ptr<betamemory> >::iterator it2=_children.begin();it2!=_children.end();it2++ ){
				std::cout<<"-------------------------------------"<<std::endl;
				std::cout<<"joinnode left activation betamemory left       "<<std::endl;
				std::cout<<"-------------------------------------"<<std::endl;
				(*it2)->beta_memory_left_activation(t,*it); //step 2
			}
		}
	}
	return true;	
}



