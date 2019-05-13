/*

time:2019.5.9
author:xcc

*/


#include "workingmemory.h"

//construction
workingmemory::workingmemory(boost::shared_ptr<alphanode> root):_wm(),_root(root){

}

//destroy
workingmemory::~workingmemory(){

}

//add a WME to WM

void workingmemory::addwme(boost::shared_ptr<WME> w){
	this->_wm.push_back(w);
	root->alphanodeactivation(w)

}

//remove a WME in WM 
void workingmemory::removewme(boost::shared_ptr<WME> w){

} //to be done

//clean the WM vector
void clean(){
	_wm.clear();
}


//get the root node after workingmemory
boost::shared_ptr<alphanode> workingmemory::getroot(){
	return _root;
}
