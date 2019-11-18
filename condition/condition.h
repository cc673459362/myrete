/*

time:2019.5.15
author:xcc

/* ORIGIN : 8 elements in condition

   OPTIMIZE: 3 elements in condition--> identifier \ attribute  \ value.
*/

#ifndef CONDITION
#define CONDITION
#include<string>
class condition{
public:
#ifndef ORIGIN
	condition(const std::string &identifier="",const std::string &attribute="",const std::string &value="");
#endif
#ifdef ORIGIN
	condition(const std::string &identifier="",const std::string &attribute="",const std::string &value="",const std::string &arg4="",const std::string &arg5="",const std::string &arg6="",const std::string &arg7="",const std::string &arg8="");
#endif	
	~condition();
	std::string getid();
	void setid(const std::string&);
	std::string getattr();
	void setattr(const std::string&);
	std::string getvalue();
	void setvalue(const std::string&);
#ifdef ORIGIN
	std::string getarg4();
	void setarg4(const std::string&);
	std::string getarg5();
	void setarg5(const std::string&);
	std::string getarg6();
	void setarg6(const std::string&);
	std::string getarg7();
	void setarg7(const std::string&);
	std::string getarg8();
	void setarg8(const std::string&);
#endif

private:
	std::string _identifier;
	std::string _attribute;
	std::string _value;
#ifdef ORIGIN
	std::string _arg4;
	std::string _arg5;
	std::string _arg6;
	std::string _arg7;
	std::string _arg8;
#endif
};
#endif
