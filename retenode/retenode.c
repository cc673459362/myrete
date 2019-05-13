/*

time:2019.5.9
author:xcc

*/

#include "retenode.h"

//construction
retenode::retenode(const std::string& type,std::list<boost::shared_ptr<retenode>> children, boost::shared_ptr<retenode> parent):_type(type),_children(children),_parent(parent){

}

//destory
retenode::~retenode(){

}


