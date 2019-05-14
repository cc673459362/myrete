/*

time:2019.5.9
author:xcc

*/

#include "retenode.h"

//construction
retenode::retenode(const std::string& type,const std::list<boost::shared_ptr<retenode>> &children,const boost::shared_ptr<retenode> &parent):_type(type),_children(children),_parent(parent){

}

//destory
retenode::~retenode(){

}

//set the parent node
void retenode::setparent(const boost::shared_ptr<retenode> &parent){
	_parent=parent;
}

//set the children node
void retenode::setchildren(const std::list<boost::shared_ptr<retenode> > &children){
	_children=children;
}

//set the type of node
void retenode::settype(const std::string &type){
	_type=type;
}

//set the terminal node
void retenode::setterminal(const boost::shared_ptr<terminalnode> &terminal){
	_terminal=terminal
}


//get the parent node
boost::shared_ptr<retenode> retenode::getparent(){
	return _parent;
}

//get tpye of node
std::string retenode::gettype(){
	return _type;
}

//get the children node
std::list<boost::shared_ptr<retenode> > retenode::getchildren(){
	return _children;
}

//get the terminal node
boost::shared_ptr<terminalnode> retenode::getterminal(){
	return _terminal;
}
