#include <iostream>

using namespace std;

struct node{
	int node_number;
	char data;
	node * left;
	node * right;
	bool is_end_node = true;
};

int tc = 1;
int count_node = 0;
int node_number;
int node_left;
int node_right;
char input_value;
node * arr_node = new node[201];

void check(int input_node_count, int tc_number){
	for (int i = 1; i < count_node; i++){
		if (arr_node[i].is_end_node){
			if (arr_node[i].data == '+' || arr_node[i].data == '-' || arr_node[i].data == '*' || arr_node[i].data == '/'){
				cout << "#" << tc_number << " 0" << '\n';
			}
		}
	}
	cout << "#" << tc_number << " 1" << '\n';
}

int main(){

	for (tc; tc <= 10; tc++){
		cin >> count_node;
		arr_node = new node[201];
		//input_value
		for (int i = 1; i <= count_node; i++){
			cin >> node_number;
			cin >> input_value;
			cin >> node_left;
			cin >> node_right;

			arr_node[node_number].data = input_value;
			arr_node[node_number].left = &arr_node[node_left];
			arr_node[node_number].right = &arr_node[node_right];
		}
		//check is right
		check(count_node, tc);
	}

	return 0;
}