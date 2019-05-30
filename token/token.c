/*

time:2019.5.9
author:xcc

*/

#include "token.h"

//construction
token::token(const int &num,const boost::shared_ptr<token> &front,const boost::shared_ptr<myWME> &myWME):_num(num),_front(front),_myWME(myWME){
	
}

//default construction
token::token():_num(1){

}

//destroy
token::~token(){

}

//get the front token
boost::shared_ptr<token> token::getfront(){
	return _front;
}

//get the current myWME
boost::shared_ptr<myWME> token::getmyWME(){
	return _myWME;
}

//get the number of the condition in the token
int token::getnum(){
	return _num;
}

//set the front token
bool token::setfront(const boost::shared_ptr<token>& t){
	_front=t;
	return true;
}

//set the wme
bool token::setmyWME(const boost::shared_ptr<myWME>& w){
	_myWME=w;
	return true;
}

//set the num
bool token::setnum(const int& n){
	_num=n;
	return true;
}
