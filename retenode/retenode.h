/*

time:2019.5.9
author:xcc

*/


#ifndef RETENODE
#define RETENODE
#include "token.h"
#include<list>
#include<string>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class retenode{
public:
	retenode(const std::string& type,std::list<boost::shared_ptr<retenode>> children, boost::shared_ptr<retenode> parent);
	virtual ~retenode() =0;	
	virtual boost::shared_ptr<retenode> getparent() =0;
	virtual std::list<boost::shared_ptr<retenode>> getchildren() =0;
	virtual std::string gettype() =0;
	virtual boost::shared_ptr<terminalnode> getterminal() =0;
private:
	boost::shared_ptr<terminalnode> _terminal;
	std::string _type;
	std::list<boost::shared_ptr<retenode>> _children;
	boost::shared_ptr<retenode> _parent;
	
};

#endif
