#ifndef BTREENODE_H
#define BTREENODE_H

template<typename recType,int bTreeOrder>
struct btreeNode {
	int recCount;
	recType list[bTreeOrder-1];
	btreeNode *m_children[bTreeOrder];
	btreeNode()
	{}
		//~btreeNode();//implementar destructor
};

#endif

