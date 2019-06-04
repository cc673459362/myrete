/*

time:2019.6.4
author:xcc

*/

#include "rule.h"

//construction
rule::rule(){
	
}

//destroy
rule::~rule(){

}

//get the name of rule
std::string rule::getname(){
	return _name;
}

//set the name of rule
bool rule::setname(const std::string name){
	_name=name;
	return true;
}

//get conditions of rule
std::list<boost::shared_ptr<condition> > rule::getconditions(){
	return _condition;
}

//set conditions of rule
bool setconditions(const std::list<boost::shared_ptr<condition> > &conds){
	_condition=conds;
	return true;
}

//get the rhs of rule
std::string rule::getrhs(){
	return _rhs;
}
