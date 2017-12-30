#ifndef BTREE_H
#define BTREE_H
#include "btreeNode.h"
template<typename recType,int bTreeOrder>
class bTree {
private:
	btreeNode<recType,bTreeOrder> *m_root;
public:
	bTree()
		:m_root(0){}
	bool search(const recType& searchItem);
	void insert(const recType& insertItem);
	void inOrder();
};

#endif

