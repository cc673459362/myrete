/*

time:2019.5.9
author:xcc

*/

#include "alphanode.h"

//construction
alphanode::alphanode(const std::string& testfield,const std::string minsymbol,const std::string maxsymbol,boost::shared_ptr<alphamemory> am,std::list<boost::shared_ptr<alphanode>> alp):_testfield(testfield),_minsymbol(minsymbol),_maxsymbol(maxsymbol),_am(am),_alp(alp){

}

//destroy
alphanode::~alphanode(){

}

//get the testfield
std::string alphanode::gettestfield(){
	return _testfield;
}

//get the minsymbol
std::string alphanode::getminsymbol(){
	return _minsymbol;
}

//get the maxsymbol
std::string alphanode::getmaxsymbol(){
	return _maxsymbol;
}

//get the alphamemory
boost::shared_ptr<alphamemory> alphanode::getalphamemory(){
	return _am;
}

//get the alp
std::list<boost::shared_ptr<alphanode>> alphanode::getalp(){
	return _alp;
}

// alphanode test the WME passed to it
/*
	two tpyes of alphanode: root node---> testfield=="NO-TEST"
				common alpha node--->testfield=="identifier" || "attribute" ||"value"

*/
void alphanode::alphanodeactivation(boost::shared_ptr<WME> w){
	if(this->_testfield!="NO-TEST"){//the node is common alpha node
		switch (this->testfield){		
			case "identifier":
				std::string v=w->getid();
				if(v!=this->_minsymbol){
					return ;
				}
				break;
			case "attribute":
				std::string v=w->getattr();
				if(v!=this->_minsymbol){
					return ;
				}      //because except "value" the other two field must be some real string(not int),so the condition must be "=",so the _minsymbol must be equal to the _maxsymbol since [_minsymbol,_maxsymbol)
				break;
			case "value":
				std::string v=w->getvalue();
				int nv=stoi(v);
				int minn=stoi(this->_minsymbol);
				int maxn=stoi(this->_maxsymbol);
				if(nv<minn||nv>=maxn){
					return ;
				}
				break;
		}
	}
	if(this->_am!=nullptr){ //the next node is alpha memory
		(this->_am)->addwme(w);
	}
	for(std::list<boost::shared_ptr<alphanode>>::iterator it=_alp.begin();it!=_alp.end();it++){
		it->alphanodeactivation(w);
	}
	
}
