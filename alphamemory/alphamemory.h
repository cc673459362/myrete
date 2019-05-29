/*

time:2019.5.9
author:xcc

*/


#ifndef ALPHAMEMORY
#define ALPHAMEMORY
#include<list>
#include "myWME.h"
#include "joinnode.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class alphamemory{
public:
	alphamemory(const std::list<boost::shared_ptr<joinnode> > &childrennode);
	alphamemory();
	~alphamemory();
	void addmyWME(boost::shared_ptr<myWME> &w);
	std::list<boost::shared_ptr<myWME> > getam();
	void setam(std::list<boost::shared_ptr<myWME> > &am);
	std::list<boost::shared_ptr<joinnode> > getchildren();
	void setchildren(std::list<boost::shared_ptr<joinnode> > &children);
private:
	std::list<boost::shared_ptr<myWME> > _am;
	std::list<boost::shared_ptr<joinnode> > _childrennode;

};

#endif
