#include <iostream>

using namespace std;

struct node {
	int data;
	node * parent;
};

int tc;
int s_n, e_n;


int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> s_n >> e_n;
	}

	//루트를 정하고, 1번부터 각각의 부모 노드번호를 출력


	return 0;
}