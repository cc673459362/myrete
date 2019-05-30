/*

time:2019.5.9
author:xcc

*/


#include "workingmemory.h"

//construction
workingmemory::workingmemory(boost::shared_ptr<alphanode> &root):_wm(),_root(root){

}

//destroy
workingmemory::~workingmemory(){

}

//add a myWME to WM

void workingmemory::addmyWME(boost::shared_ptr<myWME> &w){
	this->_wm.push_back(w);
	_root->alphanodeactivation(w);

}

//remove a myWME in WM 
void workingmemory::removemyWME(boost::shared_ptr<myWME> &w){

} //to be done

//clean the WM vector
void workingmemory::clean(){
	_wm.clear();
}


//get the root node after workingmemory
boost::shared_ptr<alphanode> workingmemory::getroot(){
	return _root;
}
