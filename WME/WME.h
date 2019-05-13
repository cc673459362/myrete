/*

time:2019.5.9
author:xcc

*/

#ifndef WME
#define WME
#include<string>
class WME{
public:
	WME(const string &id="",const string &attr="",const string &value="");
	~WME();
	std::string getid();
	void setid(std::string);
	std::string getattr();
	void setattr(std::string);
	std::string getvalue();
	void setvalue(std::string);
private:
	std::string:_identifier;
	std::string:_attribute;
	std::string:_value;
};
#endif
