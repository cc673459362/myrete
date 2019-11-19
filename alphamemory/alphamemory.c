/*

time:2019.5.9
author:xcc

*/

#include<alphamemory.h>

#ifdef BTREE

btree::btree(const int &frontseq,const int &backseq,const int &degree):_frontseq(frontseq),_backseq(backseq),_M(degree),_empty(true),_leaf(false){

}

btree::~btree(){

}

int btree::getdegree(){
	return _M;
}
void btree::setdegree(const int& M){
	_M=M;
}
	
bool btree::getleaf(){
	return _leaf;
}

void btree::setleaf(bool b){
	_leaf=b;
}

bool btree::getempty(){
	return _empty;
}

void btree::setempty(bool b){
	_empty=b;
}

int btree::getfrontseq(){
	return _frontseq;
}

void btree::setfrontseq(const int& frontseq){
	_frontseq=frontseq;
}

int btree::getbackseq(){
	return _backseq;
}

void btree::setbackseq(const int &backseq){
	_backseq=backseq;
}

std::vector<boost::shared_ptr<btree> > btree::getchildren(){
	return _children;
}

std::vector<boost::shared_ptr<joinnode> > btree::getleafnode(){
	return _leafnode;
}

void btree::setleafnode(std::vector<boost::shared_ptr<joinnode> >& leafnode){
	_leafnode=leafnode;
}

void btree::setchildren(std::vector<boost::shared_ptr<btree> >& children){
	_children=children;
}

#endif
//construction
alphamemory::alphamemory(const std::list<boost::shared_ptr<joinnode> > &childrennode):_am(),_childrennode(childrennode){

};

//default construction
alphamemory::alphamemory():_am(),_childrennode(){

}

//destroy
alphamemory::~alphamemory(){

}

#ifdef BTREE
//create btree
void alphamemory::createbtree(const int &degree){
	if(_broot!=NULL){
		std::cout<<"the am has created btree!!"<<std::endl;
		return;
	}
	int m=degree;
	int n=_childrennode.size();
	_broot=boost::make_shared<btree>(1,n,m);
	
	createchildnode(_broot,1,n,m);

	
}

void alphamemory::createchildnode(boost::shared_ptr<btree> &root,const int &frontseq,const int &backseq,const int& degree){
	if(backseq-frontseq+1<=degree){//leaf node
		boost::shared_ptr<btree> re=boost::make_shared<btree>(frontseq,backseq,degree);
		re->setleaf(true);
		int count=1;
		std::vector<boost::shared_ptr<joinnode> > leafnode;
		for(std::list<boost::shared_ptr<joinnode> >::iterator it=_childrennode.begin();it!=_childrennode.end();it++){
			if(count>=frontseq&&count<=backseq){
				leafnode.push_back(*it);	
			}
			count++;
		}
		re->setleafnode(leafnode);
		std::vector<boost::shared_ptr<btree> > child=root->getchildren();
		child.push_back(re);
		root->setchildren(child);
	}
	else{//not leaf node
		int n=backseq-frontseq+1;
		std::vector<boost::shared_ptr<btree> > children=root->getchildren();
		n=n/degree;
		for(int i=0;i<degree;i++){
			boost::shared_ptr<btree> re=boost::make_shared<btree>(frontseq+i*n,std::min(frontseq+i*n+n-1,backseq),degree);
			children.push_back(re);
		}
		root->setchildren(children);
		children=root->getchildren();
		for(std::vector<boost::shared_ptr<btree> >::iterator it=children.begin();it!=children.end();it++){
			createchildnode(*it,(*it)->getfrontseq(),(*it)->getbackseq(),degree);
		}
	}
	return;
}

void alphamemory::setnotempty(const int &num){
	cursetnotempty(this->_broot,num);
}

void alphamemory::cursetnotempty(boost::shared_ptr<btree> &root,const int &num){
	if(num>=root->getfrontseq() && num<=root->getbackseq() ){
		root->setempty(false);
	}
	std::vector<boost::shared_ptr<btree> > ch=root->getchildren();
	for(std::vector<boost::shared_ptr<btree> >::iterator it=ch.begin();it!=ch.end();it++){
		cursetnotempty(*it,num);
	}
	return;
}

#endif
//add a  myWME to the alpha memory
/*
	there are two steps:1.  add the myWME to the tail of the list
			    2. 	"notify" all the child node of the alphamemory(right-activation)
*/
void alphamemory::addmyWME(boost::shared_ptr<myWME> &w){
	this->_am.push_back(w);//step 1
	std::cout<<"-------------------------------------"<<std::endl;
	std::cout<<"push wme into the alphamemory        "<<std::endl;
	std::cout<<"size of children node       : "<<_childrennode.size()<<std::endl;
	std::cout<<"-------------------------------------"<<std::endl;
#ifndef BTREE
	for(std::list<boost::shared_ptr<joinnode> > ::iterator it=_childrennode.begin();it!=_childrennode.end();it++){
		(*it)->join_node_right_activation(w); //step 2
		
	}
#endif
#ifdef BTREE
	boost::shared_ptr<btree> broot=this->_broot;
	curempty(broot,w);
#endif

}
#ifdef BTREE
void curempty(boost::shared_ptr<btree> &root,boost::shared_ptr<myWME> &w){	
	if(root->getleaf()){//if the node is leaf node
		for(std::vector<boost::shared_ptr<joinnode> > ::iterator it=root->getleafnode().begin();it!=root->getleafnode().end();it++){
			(*it)->join_node_right_activation(w);
		}
		return;
	}	
	if(!(root->getleaf())){//if the btree node is not a leaf node
		for(std::vector<boost::shared_ptr<btree> >::iterator it=root->getchildren().begin();it!=root->getchildren().end();it++){
			if((*it)->getempty()){
				return;
			}else{
				curempty(*it,w);
			}
		}
	}
	return;
}
#endif

//get the list of alphamemory
std::list<boost::shared_ptr<myWME> > alphamemory::getam(){
	return _am;
}

//get the list of childrennode of the alphamemory
std::list<boost::shared_ptr<joinnode> > alphamemory::getchildren(){
	return _childrennode;
}

//set the list of alphamemory
void alphamemory::setam(std::list<boost::shared_ptr<myWME> > &am){
	_am=am;
}

//set the liset of childrennode of the alphamemory
void alphamemory::setchildren(std::list<boost::shared_ptr<joinnode> > &children){
	_childrennode=children;
}

