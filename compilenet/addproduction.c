/*

time:2019.5.13
author:xcc

*/

#include "addprodution.h"

//create or shared a beta memory node in beta net
/*
	this function need arg -->> the betamemorynode needed tobe create or shared 's parent node.
			1.retrieve the parent node's children ,(JOINNODE's children),if there already have a betamemory node,then  now we can shared this node.
			2.if not,then we create a new betamemory node.and insert the node to the parent's children list.

*/
boost::shared_prt<retenode> build_or_shared_beta_memory_node(boost::shared_prt<retenode> &parent){
	std::list<boost::shared_ptr<retenode>> child=parent->getchildren();
	for(std::list<boost::shared_ptr<retenode>>::iterator it=child.begin();it!=child.end();it++){
		if(child->gettype()=="betamemory"){
			return *it;
		}
	}
	boost::shared_ptr<retenode> beta=boost::make_ptr<betamemory>("betamemory",std::list<boost::shared_ptr<retenode>> children(),parent,std::list<boost::shared_ptr<token>>());//allocaate a new betamemorynode
	child.push(beta);
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
boost::shared_prt<retenode> build_or_share_join_node(boost::shared_prt<retenode> &parent,boost::shared_ptr<alphamemory> &am,std::list<boost::shared_ptr<testjoinnode>> &test){
	std::list<boost::shared_ptr<retenode>> child=parent->getchildren();
	for(std::list<boost::shared_ptr<retenode>>::iterator it=child.begin();it!=child.end();it++){
		if(it->gettype()=="joinnode"&&child->getam()==am&&child->gettest()==test)	{
			return *it;
		}
	}
	boost::shared_prt<retenode> join=boost::make_shared<joinnode>("joinnode",std::list<boost::shared_ptr<retenode> >(), parent,am,test);
	child.push(join);
	parent->setchildren(child);//insert to parent;
	std::list<boost::shared_ptr<retenode>> achild=am->getchildren();
	achild.push(join);
	am->setchildren(achild);
	return join;
	


}

