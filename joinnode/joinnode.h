/*

time:2019.5.9
author:xcc

*/


#ifndef JOINNODE
#define JOINNODE

#include "terminalnode.h"
#include<iostream>
#include<string>
#include<list>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
class alphamemory;
class  betamemory;
class testjoinnode{
public:
	testjoinnode(const std::string &field_of_arg1,const int &condition_number_of_arg2,const std::string &field_of_arg2);
	testjoinnode();
	~testjoinnode();
	std::string getarg1();
	std::string getarg2();
	int getnumberofarg2();
	bool setarg1(const std::string &arg1);
	bool setarg2(const std::string &arg2);
	bool setnumberofarg2(const int &n);
	//
	

private:
	std::string _field_of_arg1;
	int _condition_number_of_arg2;
	std::string _field_of_arg2;
};
class joinnode{
public:
	//construction
	joinnode(const std::list<boost::shared_ptr<betamemory> > &children,const boost::shared_ptr<betamemory> &parent,const boost::shared_ptr<terminalnode> &terminal,const boost::shared_ptr<alphamemory>   &am,const std::list<boost::shared_ptr<testjoinnode> > &test);
	
	//default construction
	joinnode();
	
	//destroy
	~joinnode();

	//get parent
	boost::shared_ptr<betamemory> getparent();

	//set parent
	bool setparent(boost::shared_ptr<betamemory> &parent);

	//get children
	std::list<boost::shared_ptr<betamemory> > getchildren();

	//set children
	bool setchildren(std::list<boost::shared_ptr<betamemory> > &children);

	//get terminal
	boost::shared_ptr<terminalnode> getterminal();

	//set terminal
	bool setterminal(boost::shared_ptr<terminalnode> &terminal);

	//get amparent
	boost::shared_ptr<alphamemory> getam();

	//set amparent
	bool setam(const boost::shared_ptr<alphamemory> &am); 

	//get testjoinnode
	std::list<boost::shared_ptr<testjoinnode> > gettest();

	//set testjoinnode
	bool settest(const std::list<boost::shared_ptr<testjoinnode> > &test);

	//right activation by WME
	bool join_node_right_activation(boost::shared_ptr<myWME> &w);

	//left activation by token
	bool join_node_left_activation(boost::shared_ptr<token> &t);
	
private:
	boost::shared_ptr<terminalnode> _terminal;
	std::list<boost::shared_ptr<betamemory> > _children;
	boost::shared_ptr<betamemory> _parent;
	boost::shared_ptr<alphamemory> _am;
	std::list<boost::shared_ptr<testjoinnode> > _test;
};

bool performjoinnode(std::list<boost::shared_ptr<testjoinnode> > &test,boost::shared_ptr<token> &t,boost::shared_ptr<myWME> &w);
#endif
