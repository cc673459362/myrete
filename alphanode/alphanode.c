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
				std::cout<<"identifier match failed"<<std::endl;
				std::cout<<"wme's id         = "<<v<<std::endl;
				std::cout<<"alphanode's id   = "<<_minsymbol<<std::endl;
				return ;
			}
		}	
		else if(this->_testfield=="attribute"){
			std::string v=w->getattr();
			if(v!=this->_minsymbol){
				std::cout<<"attribute match failed"<<std::endl;		
				std::cout<<"wme's attr       = "<<v<<std::endl;
				std::cout<<"alphanode's attr = "<<_minsymbol<<std::endl;		
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
			if(nv<minn||nv>maxn){
				std::cout<<"value match failed"<<std::endl;
				std::cout<<"wme's value       = "<<v<<std::endl;
				std::cout<<"alphanode's value = "<<_minsymbol<<std::endl;
				return ;
			}
		}
#ifdef ORIGIN
		if(this->_testfield=="arg4"){		
			std::string v=w->getarg4();
			if(v!=this->_minsymbol){
				std::cout<<"arg4 match failed"<<std::endl;
				std::cout<<"wme's arg4         = "<<v<<std::endl;
				std::cout<<"alphanode's arg4   = "<<_minsymbol<<std::endl;
				return ;
			}
		}
		if(this->_testfield=="arg5"){		
			std::string v=w->getarg5();
			if(v!=this->_minsymbol){
				std::cout<<"arg5 match failed"<<std::endl;
				std::cout<<"wme's arg5         = "<<v<<std::endl;
				std::cout<<"alphanode's arg5   = "<<_minsymbol<<std::endl;
				return ;
			}
		}
		if(this->_testfield=="arg6"){		
			std::string v=w->getarg6();
			if(v!=this->_minsymbol){
				std::cout<<"arg6 match failed"<<std::endl;
				std::cout<<"wme's arg6         = "<<v<<std::endl;
				std::cout<<"alphanode's arg6   = "<<_minsymbol<<std::endl;
				return ;
			}
		}
		if(this->_testfield=="arg7"){		
			std::string v=w->getarg7();
			if(v!=this->_minsymbol){
				std::cout<<"arg7 match failed"<<std::endl;
				std::cout<<"wme's arg7         = "<<v<<std::endl;
				std::cout<<"alphanode's arg7   = "<<_minsymbol<<std::endl;
				return ;
			}
		}
		if(this->_testfield=="arg8"){		
			std::string v=w->getarg8();
			if(v!=this->_minsymbol){
				std::cout<<"arg4 match failed"<<std::endl;
				std::cout<<"wme's arg8         = "<<v<<std::endl;
				std::cout<<"alphanode's arg8   = "<<_minsymbol<<std::endl;
				return ;
			}
		}
#endif			
	}
	if(this->_am!=NULL){ //the next node is alpha memory
		(this->_am)->addmyWME(w);
		std::cout<<"insert into alphamemory "<<std::endl;
	}
	for(std::list<boost::shared_ptr<alphanode> >::iterator it=_alp.begin();it!=_alp.end();it++){
		(*it)->alphanodeactivation(w);
	}
	
}
