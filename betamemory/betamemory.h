/*

time:2019.5.9
author:xcc

*/


#ifndef BETAMEMORY
#define BETAMEMORY
#include "retenode.h"
#include <memory>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class betamemory : public retenode{
public:
	//
	betamemory(const std::string &type,const std::list<boost::shared_ptr<retenode> > &children, const boost::shared_ptr<retenode> &parent,const std::list<boost::shared_ptr<token> > &item);
	~betamemory();
	void beta_memory_left_activation(boost::shared_ptr<token> &t,boost::shared_ptr<WME> &w);
	std::list<boost::shared_ptr<token>> gettoken();
	void settoken(const std::list<boost::shared_ptr<token>>);
private:
	std::list<boost::shared_ptr<token>> _item;
};
#endif
