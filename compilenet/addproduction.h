/*

time:2019.5.13
author:xcc

*/

#ifndef ADDPRODUCTION
#define ADDPRODUCTION
#include "joinnode.h"
#include "alphamemory.h"
void addproduction(std::list<std::shared_ptr<contidion>> lhs);
//
std::list<std::shared_ptr<testjoinnode>> get_join_tests_from_condition(std::shared_prt<condition> c,std::list<std::shared_ptr<condition>> earlier_conds);
//
std::shared_ptr<alphamemory> build_or_share_alphamemory(std::shared_ptr<condition> c);
//
std::shared_prt<retenode> build_or_share_join_node(std::shared_prt<retenode> currentnode,std::shared_ptr<alphamemory> am,std::list<std::shared_ptr<testjoinnode>> test)


#endif
