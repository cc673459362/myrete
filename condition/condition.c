/*

time:2019.5.15
author:xcc

*/

#include "condition.h"

//construction
condition::condition(const std::string &identifier,const std::string &attribute,const std::string &value):_identifier(identifier),_attribute(attribute),_value(value){

}

//destroy
condition::~condition(){

}

//get the identifier
std::string condition::getid(){
	return _identifier;
}

//get the attribute
std::string condition::getattr(){
	return _attribute;
}

//get the value
std::string condition::getvalue(){
	return _value;
}

//set the identifier
void condition::setid(const std::string& id){
	_identifier=id;
}

void condition::setattr(const std::string& attr){
	_attribute=attr;
}

void condition::setvalue(const std::string& value){
	_value=value;
}
