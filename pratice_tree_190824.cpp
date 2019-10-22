#include <iostream>

using namespace std;


struct node{
	int data;
	node * left;
	node * right;
};


int main(){

	node a;
	a.data = 1;

	node b;
	b.data = 2;

	node c;
	c.data = 3;

	a.left = &b;
	a.right = &c;



	return 0;
}