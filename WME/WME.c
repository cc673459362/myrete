/*

time:2019.5.9
author:xcc

*/

#include "WME.h"

//construction
WME::WME(const string &id="",const string &attr="",const string &value=""):_identifier(identifier),_attribute(attribute),_value(value){
	
}

//destroy
WME::~WME(){

}

//get the identifier
std::string WME::getid(){
	return _identifier;
}

//set the identifier
void WME::setid(std::string id){
	_identifier=id;
}

//get the attribute
std::string WME::getattr(){
	return _attribute;
}

//set the identifier
void WME::setattr(std::string attr){
	_attribute=attr;
}

//get the value
std::string WME::getvalue(){
	return _value;
}

//set the value
void WME::setvalue(std::string val){
	_value=val;
}
