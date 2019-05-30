/*

time:2019.5.9
author:xcc

*/

#include "betamemory.h"

//construction

betamemory::betamemory(const std::list<boost::shared_ptr<joinnode> > &children, const boost::shared_ptr<joinnode> &parent,const std::list<boost::shared_ptr<token> > &item):_children(children),_parent(parent),_item(item){

}

//default1 constrction
betamemory::betamemory(){

}


//destroy
betamemory::~betamemory(){

}

//set the parent node
bool betamemory::setparent(const boost::shared_ptr<joinnode> &parent){
	_parent=parent;
	return true;
}

//set the children node
bool betamemory::setchildren(const std::list<boost::shared_ptr<joinnode> > &children){
	_children=children;
	return true;
}

//get the parent node
boost::shared_ptr<joinnode> betamemory::getparent(){
	return _parent;
}

//get the children node
std::list<boost::shared_ptr<joinnode> > betamemory::getchildren(){
	return _children;
}

//get the token list
std::list<boost::shared_ptr<token> > betamemory::gettoken(){
	return _item;
}

//set the token list
bool betamemory::settoken(const std::list<boost::shared_ptr<token> > item){
	_item=item;
	return true;
}

//the betamemory node was left activation by join node
/*
	in this function,we have to do two things:1. combine the old token and the myWME to a new token
						  2. left-activation the children node(join-node) 
*/
bool betamemory::beta_memory_left_activation(const boost::shared_ptr<token> &t,const boost::shared_ptr<myWME> &w){
	if(t!=NULL){	
	int num=t->getnum();
	num+=1;	
	std::cout<<"combine a new token from joinnode's token and wme"<<std::endl;
	boost::shared_ptr<token> newt=boost::make_shared<token>(num,t,w);
	this->_item.push_back(newt);   //
	std::cout<<"push a new token into item "<<std::endl;  
	std::list<boost::shared_ptr<joinnode> > chi=this->getchildren();
	for(std::list<boost::shared_ptr<joinnode> >::iterator it=chi.begin();it!=chi.end();it++){
		(*it)->join_node_left_activation(newt);
	}
	}else{
		int num=1;	
		std::cout<<"combine a new token from joinnode's token and wme(0)"<<std::endl;
		boost::shared_ptr<token> newt=boost::make_shared<token>();
		newt->setmyWME(w);
		this->_item.push_back(newt);   //
		std::cout<<"push a new token into item(0) "<<std::endl;  
		std::list<boost::shared_ptr<joinnode> > chi=this->getchildren();
		for(std::list<boost::shared_ptr<joinnode> >::iterator it=chi.begin();it!=chi.end();it++){
			(*it)->join_node_left_activation(newt);
		}
	}
	return true;
	
}




