#include<iostream>
#include "bTree.h"
using namespace std;

int main (int argc, char *argv[]) {
	bTree<int,5> B;
	B.insert(40);
	B.insert(30);
	B.insert(70);
	B.insert(5);
	B.insert(16);
//	B.insert(80);
	B.root->print();
//	B.inOrder();
	return 0;
}

