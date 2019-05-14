/*

time:2019.5.9
author:xcc

*/


#ifndef ALPHAMEMORY
#define ALPHAMEMORY
#include<list>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class alphamemory{
public:
	alphamemory(const std::list<boost::shared_ptr<retenode>> &childrennode);
	~alphamemory();
	void addwme(boost::shared_ptr<WME> &w);
	std::list<boost::shared_ptr<WME>> getam();
	void setam(std::list<boost::shared_ptr<WME> > &am);
	std::list<boost::shared_ptr<retenode> > getchildren();
	void setchildren(std::list<boost::shared_ptr<retenode> > &children);
private:
	std::list<boost::shared_ptr<WME>> _am;
	std::list<boost::shared_ptr<retenode>> _childrennode;

};

#endif
