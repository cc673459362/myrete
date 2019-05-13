/*

time:2019.5.9
author:xcc

*/

#include "token.h"

//construction
token::token(const int &num,boost::shared_ptr<token> &front,boost::shared_ptr<WME> &wme):_num(num),_front(front),_wme(wme){
	
}

//destroy
token::~token(){

}

//get the front token
boost::shared_ptr<token> token::getfront(){
	return _front;
}

//get the current wme
boost::shared_ptr<WME> token::getwme(){
	return _wme;
}

//get the number of the condition in the token
int token::getnum(){
	return _num;
}

