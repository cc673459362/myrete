/*

time:2019.5.9
author:xcc

*/


#ifndef ALPHAMEMORY
#define ALPHAMEMORY
#include<list>
#include<iostream>
#include "myWME.h"
#include "joinnode.h"
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
#include<vector>
#include<math.h>
#include<algorithm>
#ifdef BTREE
class btree{
public:
	btree(const int &frontseq,const int &backseq,const int &degree);
	~btree();
	int getdegree();
	void setdegree(const int&);	
	bool getleaf();
	void setleaf(bool b);
	bool getempty();
	void setempty(bool b);
	int getfrontseq();
	void setfrontseq(const int&);
	int getbackseq();
	void setbackseq(const int &);
	std::vector<boost::shared_ptr<btree> > getchildren();
	std::vector<boost::shared_ptr<joinnode> > getleafnode();
	void setleafnode(std::vector<boost::shared_ptr<joinnode> >&);
	void setchildren(std::vector<boost::shared_ptr<btree> >&);
	//void btsetnotempty(const int &);
private:
	int _M;                        //degree
	int _frontseq;
	int _backseq;
	bool _empty;
	bool _leaf;
	std::vector<boost::shared_ptr<btree> > _children;
	std::vector<boost::shared_ptr<joinnode> > _leafnode; 
};
#endif
class alphamemory{
public:

	alphamemory(const std::list<boost::shared_ptr<joinnode> > &childrennode);

	alphamemory();
	~alphamemory();
#ifdef BTREE
	void createbtree(const int &degree);
	void createchildnode(boost::shared_ptr<btree> &root,const int &frontseq,const int &backseq,const int& degree);
	void setnotempty(const int &);
	void cursetnotempty(boost::shared_ptr<btree> &,const int &);
#endif
	void addmyWME(boost::shared_ptr<myWME> &w);
	std::list<boost::shared_ptr<myWME> > getam();
	void setam(std::list<boost::shared_ptr<myWME> > &am);
	std::list<boost::shared_ptr<joinnode> > getchildren();
	void setchildren(std::list<boost::shared_ptr<joinnode> > &children);
private:
#ifdef BTREE
	boost::shared_ptr<btree> _broot;
#endif
	std::list<boost::shared_ptr<myWME> > _am;
	std::list<boost::shared_ptr<joinnode> > _childrennode;

};
#ifdef BTREE
void curempty(boost::shared_ptr<btree> &root,boost::shared_ptr<myWME> &w);
#endif
#endif
