/*

time:2019.5.9
author:xcc

*/

#ifndef TOKEN
#define TOKEN
#include "myWME.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class token{
public:
	token(const int &num,const boost::shared_ptr<token> &front,const boost::shared_ptr<myWME> &myWME);
	token();
	~token();
	boost::shared_ptr<token> getfront();
	boost::shared_ptr<myWME> getmyWME();
	int getnum();
	bool setfront(const boost::shared_ptr<token>&);
	bool setmyWME(const boost::shared_ptr<myWME>&);
	bool setnum(const int&);
private:
	
	int _num;
	boost::shared_ptr<token> _front;
	boost::shared_ptr<myWME> _myWME;

};
#endif
