/*

time:2019.5.9
author:xcc

###  ORIGIN: 8 elements in WME
###  OPTIMIZE: 3 elements in WME
*/

#ifndef MYWME
#define MYWME
#include <string>
class myWME{
public:
#ifndef ORIGIN
	myWME(const std::string &id,const std::string &attr,const std::string &value);
#endif
#ifdef ORIGIN
	myWME(const std::string &id,const std::string &attr,const std::string &value,const std::string &arg4,const std::string &arg5,const std::string &arg6,const std::string &arg7,const std::string &arg8);
#endif
	~myWME();
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
