#include <iostream>
#include <stack>
#include <string>

using namespace std;

int count_node;
string s[1001];
int result;

int node_value[1001];

long long inorder() {
	for (int i = 0; i < count_node; i++) {
		//node - +,-,/,*
		if (s[i][0] > '9' || s[i][0] < '0') {

		}
		else {
			sscanf_s(&s[i][0], "%d", node_value[i]);
		}
	}
}

int main() {

	for(int i = 0; i < 10; i++){
		cin >> count_node;

		for (int i = 0; i < count_node; i++) {
			int num;
			string c;

			cin >> num;
			getline(cin, c);

			s[num] = c;
		}

		inorder();

		
		cout << "#" << i + 1 << " " << result << endl;
	}
}
