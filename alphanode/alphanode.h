/*

time:2019.5.9
author:xcc

*/
/*
	alphandoe has two types:1---> common type --> _testfield = "identifier" \"attribute" \"value";
				2---> root node   --> _testfield = "NO-TEST" and the minsymbol= "NO" maxsymbol="NO".



*/

#ifndef ALPHANODE
#define ALPHANODE
#include<memory>
#include<list>
#include<string>
#include<iostream>
#include <sstream>
#include "alphamemory.h"
#include "retenode.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class alphanode{
public:
	alphanode(const std::string& testfield,const std::string &minsymbol,const std::string &maxsymbol,const boost::shared_ptr<alphamemory> &am,const std::list<boost::shared_ptr<alphanode> >& alp);//[minsymbol,maxsymbol)
	alphanode();
	~alphanode();
	std::string gettestfield();
	void settestfield(const std::string&);
	std::string getminsymbol();
	void setminsymbol(const std::string&);
	std::string getmaxsymbol();
	void setmaxsymbol(const std::string&);
	boost::shared_ptr<alphamemory> getalphamemory();
	void setalphamemory(const boost::shared_ptr<alphamemory>&);
	std::list<boost::shared_ptr<alphanode> > getalp();
	void setalp(const std::list<boost::shared_ptr<alphanode> >&);
	void alphanodeactivation(boost::shared_ptr<myWME>& w);
private:
	std::string _testfield;
	std::string _minsymbol;
	std::string _maxsymbol;
	boost::shared_ptr<alphamemory> _am;
	std::list<boost::shared_ptr<alphanode> > _alp;
};


#endif
