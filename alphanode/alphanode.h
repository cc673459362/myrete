/*

time:2019.5.9
author:xcc

*/


#ifndef ALPHANODE
#define ALPHANODE
#include<list>
#include<string>
#include "alphamemory.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class alphanode{
public:
	alphanode(const std::string& testfield,const std::string minsymbol,const std::string maxsymbol,boost::shared_ptr<alphamemory> am,std::list<boost::shared_ptr<alphanode>> alp);//[minsymbol,maxsymbol)
	~alphanode();
	std::string gettestfield();
	std::string getminsymbol();
	std::string getmaxsymbol();
	boost::shared_ptr<alphamemory> getalphamemory();
	std::list<boost::shared_ptr<alphanode>> getalp();
	void alphanodeactivation(boost::shared_ptr<WME> w);
private:
	std::string _testfield;
	std::string _minsymbol;
	std::string _maxsymbol;
	shared_ptr<alphamemory> _am;
	std::list<boost::shared_ptr<alphanode>> _alp;
};


#endif
