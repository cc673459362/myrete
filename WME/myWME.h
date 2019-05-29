/*

time:2019.5.9
author:xcc

*/

#ifndef MYWME
#define MYWME
#include <string>
class myWME{
public:
	myWME(const std::string &id,const std::string &attr,const std::string &value);
	~myWME();
	std::string getid();
	void setid(const std::string&);
	std::string getattr();
	void setattr(const std::string&);
	std::string getvalue();
	void setvalue(const std::string&);
private:
	std::string _identifier;
	std::string _attribute;
	std::string _value;
};
#endif
