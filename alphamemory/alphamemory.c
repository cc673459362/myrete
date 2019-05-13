/*

time:2019.5.9
author:xcc

*/

#include<alphamemory.h>

//construction
alphamemory::alphamemory(std::list<boost::shared_ptr<retenode>> childrennode):_am(),_childrennode(childrennode){

};

//destroy
alphamemory::~alphamemory(){

}

//add a  WME to the alpha memory
/*
	there are two steps:1.  add the WME to the tail of the list
			    2. 	"notify" all the child node of the alphamemory(right-activation)
*/
void alphamemory::addwme(boost::shared_ptr<WME> w){
	this->_am.push(w);//step 1
	for(std::list<boost::shared_ptr<retenode>> ::iterator it=_childrennode.begin();it!=_childrennode.end();it++){
		if(it->gettype=="joinnode"){
			it->join_node_right_activation(w); //step 2
		}
	}

}

//get the list of alphamemory
std::list<boost::shared_ptr<WME>> alphamemory::getam(){
	return _am;
}

//get the list of childrennode of the alphamemory
std::list<boost::shared_ptr<retenode>> alphamemory::getchildren(){
	return _childrennode;
}


