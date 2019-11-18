/*

time:2019.5.9
author:xcc

*/

#include "myWME.h"

#ifndef ORIGIN
//construction
myWME::myWME(const std::string &id,const std::string &attr,const std::string &value):_identifier(id),_attribute(attr),_value(value){
	
}
#endif

#ifdef ORIGIN
myWME::myWME(const std::string &id,const std::string &attr,const std::string &value,const std::string &arg4,const std::string &arg5,const std::string &arg6,const std::string &arg7,const std::string &arg8):_identifier(id),_attribute(attr),_value(value),_arg4(arg4),_arg5(arg5),_arg6(arg6),_arg7(arg7),_arg8(arg8){

}
#endif

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

#ifdef ORIGIN
std::string myWME::getarg4(){
	return _arg4;
}
void myWME::setarg4(const std::string& arg4){
	_arg4=arg4;
}
std::string myWME::getarg5(){
	return _arg5;
}
void myWME::setarg5(const std::string& arg5){
	_arg5=arg5;
}
std::string myWME::getarg6(){
	return _arg6;
}
void myWME::setarg6(const std::string& arg6){
	_arg6=arg6;
}
std::string myWME::getarg7(){
	return _arg7;
}
void myWME::setarg7(const std::string& arg7){
	_arg7=arg7;
}
std::string myWME::getarg8(){
	return _arg8;
}
void myWME::setarg8(const std::string& arg8){
	_arg8=arg8;
}
#endif
