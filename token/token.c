/*

time:2019.5.9
author:xcc

*/

#include "token.h"

//construction
token::token(const int &num,const boost::shared_ptr<token> &front,const boost::shared_ptr<myWME> &myWME):_num(num),_front(front),_myWME(myWME){
	
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

