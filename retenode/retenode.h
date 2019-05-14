/*

time:2019.5.9
author:xcc

*/


#ifndef RETENODE
#define RETENODE
#include "token.h"
#include "terminal.h"
#include<list>
#include<string>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class retenode{
public:
	retenode(const std::string& type,const std::list<boost::shared_ptr<retenode> > &children, const boost::shared_ptr<retenode> &parent);
	virtual ~retenode() =0;	
	boost::shared_ptr<retenode> getparent();
	void setparent(const boost::shared_ptr<retenode> &parent);
	std::list<boost::shared_ptr<retenode> > getchildren();
	void setchildren(const std::list<boost::shared_ptr<retenode> > &children);
	std::string gettype();
	void settype(const std::string &type);
	boost::shared_ptr<terminalnode> getterminal();
	void setterminal(const boost::shared_ptr<terminalnode> &terminal);
private:
	boost::shared_ptr<terminalnode> _terminal;
	std::string _type;
	std::list<boost::shared_ptr<retenode> > _children;
	boost::shared_ptr<retenode> _parent;
	
};

#endif
