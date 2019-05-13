/*

time:2019.5.13
author:xcc

*/

#ifndef TERMINALNODE
#define TERMINALNODE
#include<list>
#include<string>
class terminalnode{
public:
	terminalnode(std::list<std::shared_ptr<token>> lefttoken,std::string num);
	~terminalnode();
	bool addtoken(std::shared_ptr<token>);
	std::string getnum();
private:
	std::string _num;
	std::list<std::shared_ptr<token>> _lefttoken;
};


#endif


