#ifndef BTREENODE_H
#define BTREENODE_H

template<typename recType,int bTreeOrder>
class btreeNode {
	protected:
		btreeNode<recType,bTreeOrder> *m_root;
	public:
		btreeNode()
			:m_root(0){}
		bool search(const recType& searchItem);
		void insert(const recType& insertItem);
		void inOrder();
		~btreeNode();//implementar destructor
};

#endif

