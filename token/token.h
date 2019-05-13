/*

time:2019.5.9
author:xcc

*/

#ifndef TOKEN
#define TOKEN
#include" WME.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class token{
public:
	token(const int &num,boost::shared_ptr<token> &front,boost::shared_ptr<WME> &wme);
	~token();
	boost::shared_ptr<token> getfront();
	boost::shared_ptr<WME> getwme();
	int getnum();
private:
	
	int _num;
	boost::shared_ptr<token> _front;
	boost::shared_ptr<WME> _wme;

};
#endif
