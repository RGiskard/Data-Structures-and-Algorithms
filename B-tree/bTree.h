#ifndef BTREE_H
#define BTREE_H
//#include "btreeNode.h"

#include <iostream>
#include <cassert>

using namespace std;
template <class recType, int bTreeOrder>
struct bTreeNode
{
	int recCount;
	recType list[bTreeOrder - 1];
	bTreeNode *children[bTreeOrder];
	bTreeNode()
		:recCount(0){}
	void print()
	{
		for(int i=0;i<recCount;i++)
			cout<<list[i]<<" ";
		cout<<endl;	
	}	
};

template <class recType, int bTreeOrder>
class bTree
{
public:
	bool search(const recType& searchItem);
	//Function to determine if searchItem is in the B-tree.
	//Postcondition: Returns true if searchItem is found in the 
	//    B-tree; otherwise, returns false.
	
	void insert(const recType& insertItem);
	//Function to insert insertItem in the B-tree.
	//Postcondition: If insertItem is not in the the B-tree, it
	//    is inserted in the B-tree.
	
	void inOrder();
	//Function to do an inorder traversal of the B-tree.
	
	bTree();
	//constructor
	
	//Add additional members as needed
	
//protected:
public:	
	bTreeNode<recType, bTreeOrder> *root; 
	
private:
	void searchNode(bTreeNode<recType, bTreeOrder> *current,
					const recType& item, 
					bool& found, int& location);
	void insertBTree(bTreeNode<recType, bTreeOrder> *, const recType&, const recType&, 
					 bTreeNode<recType,bTreeOrder> *, bool&);
	void insertNode(bTreeNode<recType, bTreeOrder> *current,
					const recType& insertItem,
					bTreeNode<recType, bTreeOrder>* &rightChild,
					int insertPosition);
	void splitNode (bTreeNode<recType, bTreeOrder> *current,
					const recType& insertItem,
					bTreeNode<recType, bTreeOrder>* rightChild,
					int insertPosition,
					bTreeNode<recType, bTreeOrder>* &rightNode,
					recType &median);
	void recInorder(bTreeNode<recType, bTreeOrder> *current);
};

template <class recType, int bTreeOrder>
bTree<recType, bTreeOrder>::bTree()
{
	root = NULL;
} //end constructor

template <class recType, int bTreeOrder>
bool bTree<recType, bTreeOrder>::search(const recType& searchItem)
{
	bool found = false;
	int location;
	
	bTreeNode<recType, bTreeOrder> *current;
	
	current = root;
	
	while (current != NULL && !found)
	{
		searchNode(current, searchItem, found, location);
		
		if (!found)
			current = current->children[location];
	}
	
	return found;
} //end search

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::searchNode
	(bTreeNode<recType, bTreeOrder> *current,
	 const recType& item, 
	 bool& found, int& location)
{
	location = 0;
	
	while (location < current->recCount 
		   && item > current->list[location])
		location++;
	
	if (location < current->recCount 
		&& item == current->list[location])
		found = true;
	else
		found = false;
} //end searchNode

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insert(const recType& insertItem)
{
	bool isTaller = false;
	recType median;
	
	bTreeNode<recType, bTreeOrder> *rightChild;
	
	insertBTree(root, insertItem, median, 
				rightChild, isTaller);
	
	if (isTaller) //the tree is initially empty or the root
		//was split by the function insertBTree
	{
		bTreeNode<recType, bTreeOrder> *tempRoot;
		tempRoot = new bTreeNode<recType, bTreeOrder>;
		tempRoot->recCount = 1;
		tempRoot->list[0] = median;
		tempRoot->children[0] = root;
		tempRoot->children[1] = rightChild;
		
		root = tempRoot;
	}
} //insert

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insertBTree
	(bTreeNode<recType, bTreeOrder> * initNode, const recType& insertItem, const recType& median, 
	 bTreeNode<recType,bTreeOrder> *rightChild, bool &isTaller)
{
	/*Search the tree to see if the key is already in the tree*/
	bool found;
	int location=0;
	cout<<"Valor a insertar: "<<insertItem<<endl;
	if(root!=NULL){//en caso haya un elemento
		searchNode(initNode,insertItem,found,location);
		if(found)
		{
			cout<<"El elemento ya está insertado"<<endl;
			//return;
		}
		else
		{
			cout<<"La posicion:"<<location<<endl;
			if(initNode->recCount<bTreeOrder-1)
				insertNode(initNode,insertItem,rightChild,location);
		}   
	}
	else
	{
		//bTreeNode<recType, bTreeOrder>* rightChild=initNode->children[location+1];
		root=new bTreeNode<recType, bTreeOrder>();
		insertNode(root,insertItem,rightChild,location);
	}  
} //insertBTree

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insertNode
	(bTreeNode<recType, bTreeOrder> *current,
	 const recType& insertItem,
	 bTreeNode<recType, bTreeOrder>* &rightChild,
	 int insertPosition)
{
	int index;
	
	for (index = current->recCount; index > insertPosition; 
	index--)
	{
		current->list[index] = current->list[index - 1];
		current->children[index + 1] = current->children[index];
	}
	
	current->list[index] = insertItem;
	current->children[index + 1] = rightChild;
	current->recCount++;
} //end insertNode

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::splitNode
	(bTreeNode<recType, bTreeOrder> *current,
	 const recType& insertItem,
	 bTreeNode<recType, bTreeOrder>* rightChild,
	 int insertPosition,
	 bTreeNode<recType, bTreeOrder>* &rightNode,
	 recType &median)
{
	rightNode = new bTreeNode<recType, bTreeOrder>;
	
	int mid = (bTreeOrder - 1)  / 2;
	
	if (insertPosition <= mid) //new item goes in the first 
		//half of the node
	{
		int index = 0;
		int i = mid;
		
		while (i < bTreeOrder - 1)
		{
			rightNode->list[index] = current->list[i];
			rightNode->children[index + 1] = 
				current->children[i + 1];
			index++;
			i++;
		}
		
		current->recCount = mid;
		insertNode(current, insertItem, rightChild, 
				   insertPosition);
		(current->recCount)--;
		
		median = current->list[current->recCount];
		
		rightNode->recCount = index;
		rightNode->children[0] = 
			current->children[current->recCount + 1];
	}
	else  //new item goes in the second half of the node
	{
		int i = mid + 1;
		int index = 0;
		
		while (i < bTreeOrder - 1)
		{
			rightNode->list[index] = current->list[i];
			rightNode->children[index + 1] = 
				current->children[i + 1];
			index++;
			i++;
		}
		
		current->recCount = mid;
		rightNode->recCount = index;  
		
		median = current->list[mid]; 
		insertNode(rightNode, insertItem, rightChild, 
				   insertPosition - mid - 1);
		rightNode->children[0] = 
			current->children[current->recCount + 1];
	}
} //splitNode

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::inOrder()
{
	recInorder(root);
} // end inOrder

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::recInorder
	(bTreeNode<recType, bTreeOrder> *current)
{
	if (current != NULL)
	{
		recInorder(current->children[0]);
		
		for (int i = 0; i < current->recCount; i++)
		{ 
			cout << current->list[i] << " ";
			
			recInorder(current->children[i + 1]);
		}
	}
} //end recInorder

#endif

