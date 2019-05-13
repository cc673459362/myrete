/*

time:2019.5.13
author:xcc

*/

#include "addprodution.h"

//create of shared a beta memory node in beta net
std::shared_prt<retenode> build_or_shared_beta_memory_node(std::shared_prt<retenode> &parent){
	std::list<std::shared_ptr<retenode>> child=parent->getchildren();
	for(std::list<std::shared_ptr<retenode>>::iterator it=child.begin();it!=child.end();it++){
		if(child->gettype()=="betamemory"){
			return child;
		}
	}
	std::shared_ptr<retenode> =std::make_ptr<retenode>()


}
