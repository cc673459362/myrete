/*

time:2019.5.13
author:xcc

*/

#include "terminalnode.h"
#include "addproduction.h"
std::vector<std::pair<std::string,std::string> > rhs=createrhs();
//construction
terminalnode::terminalnode(const std::list<boost::shared_ptr<token> > &lefttoken,const std::string &num):_lefttoken(lefttoken),_num(num){
	
}

//default construction1
terminalnode::terminalnode(const std::string &num):_num(num),_lefttoken(){
	
}

//default construction2
//terminalnode::terminalnode():_num("0"),_lefttoken(){

//}

//destroy
terminalnode::~terminalnode(){
	
}

//get the terminal node 's num
std::string terminalnode::getnum(){
	return _num;
}

//a token was add to termianlnode from betamemory
/*
	two steps:1.push the token in to the list of lefttoken
		  2.push the terminal's request to the agenda
		  3.if the agenda response OK to terminal node,then delete the token from lefttoken.
		  4.if response from agenda is FALSE ,then retry 2.push request .

**/
bool terminalnode::addtoken(boost::shared_ptr<token> &t,boost::shared_ptr<myWME> &w){
	int num=t->getnum();
	num+=1;	
	boost::shared_ptr<token> newt=boost::make_shared<token>(num,t,w);
	this->_lefttoken.push_back(newt);
	std::cout<<"there is terminalnode addtoken!"<<std::endl;
	std::cout<<"rhs.size : "<<rhs.size()<<std::endl;
	std::cout<<"rhs.second : "<<rhs.begin()->second<<std::endl;
	std::cout<<"rhs.first : "<<rhs.begin()->first<<std::endl;
	//request to agenda using num
	for(std::vector<std::pair<std::string,std::string> >::iterator it=rhs.begin();it!=rhs.end();it++){
		if(it->second==_num){
			std::cout<<"***TERMINAL   OUT***"<<std::endl;
			std::cout<<it->first<<std::endl;
			std::cout<<"***TERMINAL   OUT***"<<std::endl;

		}
	}
	

	
	
}
