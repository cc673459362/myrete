/*

time:2019.5.15
author:xcc

*/

#include "condition.h"
#ifndef ORIGIN
//construction
condition::condition(const std::string &identifier,const std::string &attribute,const std::string &value):_identifier(identifier),_attribute(attribute),_value(value){

}
#endif 
#ifdef ORIGIN
condition::condition(const std::string &identifier,const std::string &attribute,const std::string &value,const std::string &arg4,const std::string &arg5,const std::string &arg6,const std::string &arg7,const std::string &arg8):_identifier(identifier),_attribute(attribute),_value(value),_arg4(arg4),_arg5(arg5),_arg6(arg6),_arg7(arg7),_arg8(arg8){

}
#endif

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

#ifdef ORIGIN
//get the arg4
std::string condition::getarg4(){
	return _arg4;
}

//set the arg4
void condition::setarg4(const std::string& arg4){
	_arg4=arg4;
}
//get the arg5
std::string condition::getarg5(){
	return _arg5;
}

//set the arg5
void condition::setarg5(const std::string& arg5){
	_arg5=arg5;
}
//get the arg6
std::string condition::getarg6(){
	return _arg6;
}

//set the arg6
void condition::setarg6(const std::string& arg6){
	_arg6=arg6;
}
//get the arg7
std::string condition::getarg7(){
	return _arg7;
}

//set the arg7
void condition::setarg7(const std::string& arg7){
	_arg7=arg7;
}
//get the arg8
std::string condition::getarg8(){
	return _arg8;
}

//set the arg8
void condition::setarg8(const std::string& arg8){
	_arg8=arg8;
}
#endif
