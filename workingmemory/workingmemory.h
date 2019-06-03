/*

time:2019.5.9
author:xcc

*/

#ifndef WORKINGMEMORY
#define WORKINGMEMORY
#include "myWME.h"
#include "alphanode.h"
#include<vector>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class workingmemory{
public:
	workingmemory(const boost::shared_ptr<alphanode> &root);
	~workingmemory();
	void addmyWME(boost::shared_ptr<myWME> &w);
	void removemyWME(boost::shared_ptr<myWME> &w);    //to be done
	void clean();	       
	boost::shared_ptr<alphanode> getroot();

private:
	std::vector<boost::shared_ptr<myWME> > _wm;
	
	boost::shared_ptr<alphanode> _root;
};

#endif
