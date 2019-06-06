/*

time:2019.5.13
author:xcc

*/

#ifndef TERMINALNODE
#define TERMINALNODE
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include "token.h"
#include "myWME.h"
#include "rule.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class terminalnode{
public:
	terminalnode(const std::list<boost::shared_ptr<token> > &lefttoken,const std::string &num);
	//terminalnode(const boost::shared_ptr<rule> &rule);
	terminalnode(const std::string &num="0");
	//terminalnode();
	~terminalnode();
	bool addtoken(const boost::shared_ptr<token>&, const boost::shared_ptr<myWME>&);
	std::string getnum();
private:
	std::string _num;
	std::list<boost::shared_ptr<token> > _lefttoken;
};


#endif


