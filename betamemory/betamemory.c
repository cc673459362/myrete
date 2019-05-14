/*

time:2019.5.9
author:xcc

*/

#include "betamemory.h"

//construction

betamemory::betamemory(const std::string type,const std::list<boost::shared_ptr<retenode>> children, const boost::shared_ptr<retenode> parent,const std::list<boost::shared_ptr<token>> item):retenode(type,children,parent),_item(item){

}

//destroy
betamemory::~betamemory(){

}
//the betamemory node was left activation by join node
/*
	in this function,we have to do two things:1. combine the old token and the wme to a new token
						  2. left-activation the children node(join-node) //if have terminal node , add the token into terminal
*/
void betamemory::beta_memory_left_activation(boost::shared_ptr<token> &t,boost::shared_ptr<WME> &w){	
	int num=t->getnum();
	num+=1;	
	boost::shared_ptr<token> newt=boost::make_shared<token>(num,t,w);
	this->_item.push(newt);   //  
	if((boost::shared_ptr<terminalnode> tn=this->getterminal())!=NULL){
		tn->addtoken(newt);      //add to the terminal node
	}
	std::list<boost::shared_ptr<retenode>> chi=this->getchildren();
	for(std::list<boost::shared_ptr<retenode>>::iterator it=chi.begin();it!=chi.end();it++){
		it->join_node_left_activation(newt);
	}
	
}

//get the token list
std::list<boost::shared_ptr<token> > betamemory::gettoken(){
	return _item;
}

//set the token list
void betamemory::settoken(const std::list<boost::shared_ptr<token>> item){
	_item=item;
}



