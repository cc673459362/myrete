/*

time:2019.5.9
author:xcc

*/

#include<alphamemory.h>

//construction
alphamemory::alphamemory(const std::list<boost::shared_ptr<joinnode> > &childrennode):_am(),_childrennode(childrennode){

};

//default construction
alphamemory::alphamemory():_am(),_childrennode(){

}

//destroy
alphamemory::~alphamemory(){

}

//add a  myWME to the alpha memory
/*
	there are two steps:1.  add the myWME to the tail of the list
			    2. 	"notify" all the child node of the alphamemory(right-activation)
*/
void alphamemory::addmyWME(boost::shared_ptr<myWME> &w){
	this->_am.push_back(w);//step 1
	std::cout<<"-------------------------------------"<<std::endl;
	std::cout<<"push wme into the alphamemory        "<<std::endl;
	std::cout<<"size of children node       : "<<_childrennode.size()<<std::endl;
	std::cout<<"-------------------------------------"<<std::endl;
	for(std::list<boost::shared_ptr<joinnode> > ::iterator it=_childrennode.begin();it!=_childrennode.end();it++){
		(*it)->join_node_right_activation(w); //step 2
		
	}

}

//get the list of alphamemory
std::list<boost::shared_ptr<myWME> > alphamemory::getam(){
	return _am;
}

//get the list of childrennode of the alphamemory
std::list<boost::shared_ptr<joinnode> > alphamemory::getchildren(){
	return _childrennode;
}

//set the list of alphamemory
void alphamemory::setam(std::list<boost::shared_ptr<myWME> > &am){
	_am=am;
}

//set the liset of childrennode of the alphamemory
void alphamemory::setchildren(std::list<boost::shared_ptr<joinnode> > &children){
	_childrennode=children;
}

