/*

time:2019.5.9
author:xcc

*/


#ifndef JOINNODE
#define JOINNODE
#include "retenode.h"
#include<string>
#include<list>
#include<alphamemory>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class testjoinnode{
public:
	testjoinnode(const std::string field_of_arg1,int condition_number_of_arg2,const std::string field_of_arg2);
	~testjoinnode();
	std::string getarg1();
	std::string getarg2();
	int getnumberofarg2();
	void setarg1(const std::string &arg1);
	void setarg2(const std::string &arg2);
	void setnumberofarg2(const int &n);
	//
	

private:
	std::string _field_of_arg1;
	int _condition_number_of_arg2;
	std::string _field_of_arg2;
};
class joinnode : public retenode{
public:
	//
	joinnode(const std::string type,std::list<boost::shared_ptr<retenode>> children,bost::shared_ptr<retenode> parent,boost::shared_ptr<alphamemory>   am,std::list<boost::shared_ptr<testjoinnode>> test);
	~joinnode();
	boost::shared_ptr<retenode> getparent();
	std::list<boost::shared_ptr<retenode>> getchildren();
	std::string gettype();
	boost::shared_ptr<terminalnode> getterminal()
	boost::shared_ptr<alphamemory> getam();
	void join_node_right_activation(boost::shared_ptr<WME> w);
	void join_node_left_activation(boost::shared_ptr<token> t);
	
private:
	boost::shared_ptr<alphamemory> _am;
	std::list<boost::shared_ptr<testjoinnode>> _test;
};

bool performjoinnode(std::list<boost::shared_ptr<testjoinnode>> test,boost::shared_ptr<token> t,boost::shared_ptr<WME> w);
#endif
