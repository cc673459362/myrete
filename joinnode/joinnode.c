/*

time:2019.5.9
author:xcc

*/

#include "joinnode.h"
/********      testjoinnode     ********/

//construction
testjoinnode::testjoinnode(const std::string field_of_arg1,int condition_number_of_arg2,const std::string field_of_arg2):_field_of_arg1(field_of_arg1),_condition_number_of_arg2(condition_number_of_arg2),_field_of_arg2(field_of_arg2){
	

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
void testjoinnode::setarg1(const std::string &arg1){
	_field_of_arg1=arg1;
}

//set the arg2
void testjoinnode::setarg2(const std::string &arg2){
	_field_of_arg2=arg2;
}

//set the number of arg2 in condition
void testjoinnode::setnumberofarg2(const int &n){
	_condition_number_of_arg2=n;
}

/********     end of testjoinnode     ********/


/********        joinnode             ********/

//construction
joinnode::joinnode(const std::string type,std::list<boost::shared_ptr<retenode>> children,bost::shared_ptr<retenode> parent,boost::shared_ptr<alphamemory>   am,std::list<boost::shared_ptr<testjoinnode>> test):retenode(type,children,parent),_am(am),_test(test){
	
}


//destroy
joinnode::~joinnode(){

}

//get the parent node
boost::shared_ptr<retenode> joinnode::getparent(){
	return _parent;
}

//get tpye of node
std::string joinnode::gettype(){
	return _type;
}

//get the children node
std::list<boost::shared_ptr<retenode>> joinnode::getchildren(){
	return _children;
}

//get the terminal node
boost::shared_ptr<terminalnode> joinnode::getterminal(){
	return _terminal;
}
//get the alphamemory node
boost::shared_ptr<alphamemory> joinnode::getam(){
	return _am;
}


// join node's combile test
/*
	the arg1 test means the combine condition of this join node
	the arg2 t    means the parent node's token
	the arg3 w    means the alpha memory's new WME which active the right activation
*/
bool performjoinnode(std::list<boost::shared_ptr<testjoinnode>> test,boost::shared_ptr<token> t,boost::shared_ptr<WME> w){
	for(std::list<boost::shared_ptr<testjoinnode>>::iterator it=test.begin();it!=test.end();it++){
		std::string arg1=it->getarg1();
		if(arg1=="identifier"){
			arg1=w->getid();
		}
		else if(arg1=="attribute"){
			arg1=w->getattr();
		}
		else if(arg1=="value"){
			arg1=w->getvalue();
		}//arg1
		int n=it->getnumberofarg2();
		boost::shared_ptr<WME> w2;
		w2.reset();// set the w2==NULL;
		while(t){
			if(t->getnum()==n){
				w2=t->getwme();
				break;
			}
			t=t->getfront();
		}//w2
		std::string arg2=it->getarg2();
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
					    	   2. left activation the betamemory,also means pass the new token to the children node
*/
void joinnode::join_node_right_activation(boost::shared_ptr<WME> w){
	boost::shared_ptr<retenode> parent=this->getparent();
	std::list<boost::shared_ptr<token>> partoken=parent->gettoken();
	for(std::list<boost::shared_ptr<token>>::iterator it=partoken.begin();it!=partoken.end();it++){
		if(performjoinnode(this->_test,it,w){   //setp 1
			for(std::list<boost::shared_ptr<retenode>>::iterator it2=_children.begin();it2!=_children.end();it2++ ){
				it2->beta_memory_left_activation(it,w); //step 2
			}		
		}
	}
}

//the joinnode was left activation by it's parent->left_betamemroy_activation
void joinnode::join_node_left_activation(boost::shared_ptr<token> t){
	boost::shared_ptr<alphamemory> am=this->getam();
	std::list<boost::shared_ptr<WME>> wmes=am->getam();
	for(std::list<boost::shared_ptr<WME>> ::iterator it=wmes.begin();it!=wmes.end();it++){
		if(performjoinnode(this->test,t,it)){
			for(std::list<boost::shared_ptr<retenode>::iterator it2=_children.begin();it2!=_children.end();it2++ ){
				it2->beta_memory_left_activation(t,it); //step 2
			}
		}
	}
	
}



