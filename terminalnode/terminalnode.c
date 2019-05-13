/*

time:2019.5.13
author:xcc

*/

#include "terminalnode.h"

//construction
terminalnode::terminalnode(std::list<std::shared_ptr<token>> lefttoken,std::string num):_lefttoken(lefttoken),_num(num){
	
}

//destroy
termianlnode::~terminalnode(){
	
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
bool terminalnode::addtoken(std::shared_ptr<token> t){
	(this->_lefttoken).push(t);//1
	std::string s=this->getnum();
	//request to agenda using num


	
	
}
