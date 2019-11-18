/*

time:2019.5.13
author:xcc

*/

#ifndef ADDPRODUCTION
#define ADDPRODUCTION
#include<ctime>
#include<list>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include "rule.h"
#include "joinnode.h"
#include "alphamemory.h"
#include "betamemory.h"
#include "joinnode.h"
#include "alphanode.h"
#include "condition.h"
#include "workingmemory.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>

/***************************************BETA NET***********************************/


/*
	build or share beta memory node:
	arg1   ---> joinnode:parent
	return ---> betamemory:betamemory

*/

boost::shared_ptr<betamemory> build_or_share_beta_memory_node(boost::shared_ptr<joinnode> &parent);

/*
	build or share join node:
	arg1   ---> betamemory:parent
	arg2   ---> alphamemory:am
	arg3   ---> list:testjoinnode
	return ---> joinnode:joinnode
*/
boost::shared_ptr<joinnode> build_or_share_join_node(boost::shared_ptr<betamemory> &parent,boost::shared_ptr<alphamemory> &am,std::list<boost::shared_ptr<testjoinnode> > &test);

/*
	get join test node from condition:
	arg1   ---> condition:C
	arg2   ---> list:earlier_condition
	return ---> list:testjoinnode
	
*/
std::list<boost::shared_ptr<testjoinnode> > get_join_tests_from_condition(boost::shared_ptr<condition> &c,std::list<boost::shared_ptr<condition> > &earlierconds);



/***********************************END OF BETA NET**********************************/




/***************************************ALPHA NET***************************************/


/**
	build or share constant test node:
	arg1   ---> alphanode:parent
	arg2   ---> string:field
	arg3   ---> string:symbol
	return ---> alphanode:constant test node
*/
boost::shared_ptr<alphanode> build_or_share_constant_test_node(const boost::shared_ptr<alphanode> &parent,const std::string field,const std::string symbol);

/**
	build or share alphamemory node:
	arg1   ---> condition:c
	arg2   ---> alphanode:root
	return ---> alphamemory:alphamemory
*/
boost::shared_ptr<alphamemory> build_or_share_alphamemory(boost::shared_ptr<condition> &c,boost::shared_ptr<alphanode> &root);



/*********************************END OF ALPHA NET**************************************/


 


/**********************************READ FILE***************************************/



/*
	create conditon from rule.txt
	return ---> list:condition
**/
std::list<boost::shared_ptr<condition> > createconditions();

/*
	create RHS vector from rule.txt
	return ---> vector:rhs
**/
std::vector<std::pair<std::string,std::string> > createrhs();

/*
	create rules from rule.txt
	return ---> list:rule
*/
std::list<boost::shared_ptr<rule> > createrules();

/*
	get data from data/data and form data to WME and insert it to wm.
	return ---> vector:rhs
**/
void getdataintowm(boost::shared_ptr<workingmemory> &wm,std::ifstream &in,int &timesum);

/*
	get first half symbol from "minsymbol,maxsymbol"
	arg1   ---> string:symbol
	return ---> string:minsymbol
*/
std::string mygetfirst(const std::string &symbol);

/*
	get second half symbol from "minsymbol,maxsymbol"
	arg1   ---> string:symbol
	return ---> string:maxsymbol
*/
std::string mygetsecond(const std::string &symbol);


/***********************************END OF READ FILE********************************/




/********************************CREATE FULL NET FROM CONDITIONS**********************/
/*
	create net from conditions
	arg1   ---> list:conditions
	arg2   ---> betamemory:dummynode
	arg3   ---> alphanode:root
	return ---> bool
*/
bool add_production(const boost::shared_ptr<rule> &rule,boost::shared_ptr<betamemory> &dummynode,boost::shared_ptr<alphanode> &root);


/*************************END OF CREATE FULL NET FROM CONDITIONS**********************/
#endif
