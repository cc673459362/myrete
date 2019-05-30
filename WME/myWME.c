/*

time:2019.5.9
author:xcc

*/

#include "myWME.h"

//construction
myWME::myWME(const std::string &id,const std::string &attr,const std::string &value):_identifier(id),_attribute(attr),_value(value){
	
}

//destroy
myWME::~myWME(){

}

//get the identifier
std::string myWME::getid(){
	return _identifier;
}

//set the identifier
void myWME::setid(const std::string& id){
	_identifier=id;
}

//get the attribute
std::string myWME::getattr(){
	return _attribute;
}

//set the identifier
void myWME::setattr(const std::string& attr){
	_attribute=attr;
}

//get the value
std::string myWME::getvalue(){
	return _value;
}

//set the value
void myWME::setvalue(const std::string& val){
	_value=val;
}
