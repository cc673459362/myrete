/*

time:2019.6.4
author:xcc

*/

#ifndef RULE
#define RULE
#include "condition.h"
#include<#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>>
class rule{
public:
	//construction
	rule();
	
	//destroy
	~rule();
	
	//get the name of rule
	std::string getname();

	//set the name of rule
	bool setname(const std::string &name);

	//get the conditions of rule
	std::list<boost::shared_ptr<condition> > getconditions();
	
	//set the conditions of rule
	bool setconditions(const std::list<boost::shared_ptr<condition> > &conds);

	//get the rhs of rule
	std::string getrhs();

	//set the rhs of rule
	bool setrhs(const std::string &rhs);
private:
	std::string _name;
	std::list<boost::shared_ptr<condition> > _condition;
	std::string _rhs;
};
#endif
