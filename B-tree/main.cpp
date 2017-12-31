#include<iostream>
#include "bTree.h"
using namespace std;

int main (int argc, char *argv[]) {
	bTree<int,32> B;
	const int value=1;
	B.insert(value);
	return 0;
}

