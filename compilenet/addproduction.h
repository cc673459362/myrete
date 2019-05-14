/*

time:2019.5.13
author:xcc

*/

#ifndef ADDPRODUCTION
#define ADDPRODUCTION
#include "joinnode.h"
#include "alphamemory.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
void addproduction(std::list<boost::shared_ptr<contidion>> lhs);
//
std::list<boost::shared_ptr<testjoinnode>> get_join_tests_from_condition(boost::shared_prt<condition> c,std::list<boost::shared_ptr<condition>> earlier_conds);
//
boost::shared_ptr<alphamemory> build_or_share_alphamemory(boost::shared_ptr<condition> c);
//
boost::shared_prt<retenode> build_or_share_join_node(boost::shared_prt<retenode> &parent,boost::shared_ptr<alphamemory> &am,std::list<boost::shared_ptr<testjoinnode>> &test);
//
boost::shared_prt<retenode> build_or_shared_beta_memory_node(boost::shared_prt<retenode> &parent);


#endif
