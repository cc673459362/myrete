/*

time:2019.5.9
author:xcc

*/

#ifndef WORKINGMEMORY
#define WORKINGMEMORY
#include "WME.h"
#include "alphanode.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class workingmemory{
public:
	workingmemory(boost::shared_ptr<alphanode> root);
	~workingmemory();
	void addwme(boost::shared_ptr<WME> w);
	void remove(boost::shared_ptr<WME> w);    //to be done
	void clean();	       
	boost::shared_ptr<alphanode> getroot();

private:
	std::vector<boost::shared_ptr<WME>> _wm;
	
	boost::shared_ptr<alphanode> _root;
};

#endif
