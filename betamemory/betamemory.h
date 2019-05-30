/*

time:2019.5.9
author:xcc

*/


#ifndef BETAMEMORY
#define BETAMEMORY
#include <iostream>
#include "joinnode.h"
#include "token.h"
#include <memory>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class betamemory{
public:
	//construction
	betamemory(const std::list<boost::shared_ptr<joinnode> > &children, const boost::shared_ptr<joinnode> &parent,const std::list<boost::shared_ptr<token> > &item);
	
	//default construction
	betamemory();

	//destroy 
	~betamemory();

	//get parent node
	boost::shared_ptr<joinnode> getparent();

	//set parent node
	bool setparent(const boost::shared_ptr<joinnode> &parent);

	//get children node
	std::list<boost::shared_ptr<joinnode> > getchildren();

	//set children node
	bool setchildren(const std::list<boost::shared_ptr<joinnode> > &children);

	//node left activation
	bool beta_memory_left_activation(const boost::shared_ptr<token> &t,const boost::shared_ptr<myWME> &w);

	//get token
	std::list<boost::shared_ptr<token> > gettoken();

	//set token
	bool settoken(const std::list<boost::shared_ptr<token> >);
private:
	
	std::list<boost::shared_ptr<joinnode> > _children;
	boost::shared_ptr<joinnode> _parent;
	std::list<boost::shared_ptr<token> > _item;
};
#endif
