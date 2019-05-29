/*

time:2019.5.15
author:xcc

*/
#ifndef CONDITION
#define CONDITION
#include<string>
class condition{
public:
	condition(const std::string &identifier="",const std::string &attribute="",const std::string &value="");
	~condition();
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
