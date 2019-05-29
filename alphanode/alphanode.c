/*

time:2019.5.9
author:xcc

*/

#include "alphanode.h"

//construction1
alphanode::alphanode(const std::string& testfield,const std::string& minsymbol,const std::string& maxsymbol,const boost::shared_ptr<alphamemory> &am,const std::list<boost::shared_ptr<alphanode> > &alp):_testfield(testfield),_minsymbol(minsymbol),_maxsymbol(maxsymbol),_am(am),_alp(alp){

}

//construction2
alphanode::alphanode(){
	
}

//destroy
alphanode::~alphanode(){

}

//get the testfield
std::string alphanode::gettestfield(){
	return _testfield;
}

//set the testfield
void alphanode::settestfield(const std::string& testfield){
	_testfield=testfield;
}

//get the minsymbol
std::string alphanode::getminsymbol(){
	return _minsymbol;
}

//set the minsybol
void alphanode::setminsymbol(const std::string& minsymbol){
	_minsymbol=minsymbol;
}


//get the maxsymbol
std::string alphanode::getmaxsymbol(){
	return _maxsymbol;
}

//set the maxsymbol
void alphanode::setmaxsymbol(const std::string& maxsymbol){
	_maxsymbol=maxsymbol;
}

//get the alphamemory
boost::shared_ptr<alphamemory> alphanode::getalphamemory(){
	return _am;
}

//set the alphamemory
void alphanode::setalphamemory(const boost::shared_ptr<alphamemory>& am){
	_am=am;
}

//get the alp
std::list<boost::shared_ptr<alphanode> > alphanode::getalp(){
	return _alp;
}

//set the alp
void alphanode::setalp(const std::list<boost::shared_ptr<alphanode> >& alp){
	_alp=alp;
}
// alphanode test the myWME passed to it
/*
	two tpyes of alphanode: root node---> testfield=="NO-TEST"
				common alpha node--->testfield=="identifier" || "attribute" ||"value"

*/
void alphanode::alphanodeactivation(boost::shared_ptr<myWME>& w){
	if(this->_testfield!="NO-TEST"){//the node is common alpha node
		if(this->_testfield=="identifier"){		
			std::string v=w->getid();
			if(v!=this->_minsymbol){
				return ;
			}
		}
				
		else if(this->_testfield=="attribute"){
			std::string v=w->getattr();
			if(v!=this->_minsymbol){
				return ;
			}      //because except "value" the other two field must be some real string(not int),so the condition must be "=",so the _minsymbol must be equal to the _maxsymbol since [_minsymbol,_maxsymbol)
		}
		else if(this->_testfield=="value"){
			std::string v=w->getvalue();
			std::istringstream ss(v);
			int nv;
			ss>>nv;
			std::istringstream ss1(this->_minsymbol);
			int minn;
			ss1>>minn;
			std::istringstream ss2(this->_maxsymbol);;
			int maxn;
			ss2>>maxn;
			if(nv<minn||nv>=maxn){
				return ;
			}
		}
				
		
	}
	if(this->_am!=NULL){ //the next node is alpha memory
		(this->_am)->addmyWME(w);
	}
	for(std::list<boost::shared_ptr<alphanode> >::iterator it=_alp.begin();it!=_alp.end();it++){
		(*it)->alphanodeactivation(w);
	}
	
}
