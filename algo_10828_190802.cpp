#include <iostream>

using namespace std;

int count_command;
char input_command[10000];
int arr_stack[10000] = { 0, };
int current_index = 0;
int input_value;

int main() {

	cin >> count_command;

	for (int i = 0; i < count_command; i++) {
		cin >> input_command;
		
		if (input_command[0] == 'p') {
			//push
			if (input_command[1] == 'u') {
				cin >> input_value;
				arr_stack[current_index++] = input_value;
			}
			//pop
			else {
				if (current_index > 0) {
					cout << arr_stack[--current_index] << '\n';
				}
				else {
					cout << "-1" << '\n';
				}
			}
		}
		//top
		if (input_command[0] == 't') {
			if (current_index > 0) {
				cout << arr_stack[current_index -1] << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		//size
		if (input_command[0] == 's') {
			if (current_index > 0) {
				cout << current_index;
				cout << '\n';
			}
			else {
				cout << "0";
				cout << '\n';
			}
		}
		//empty
		if (input_command[0] == 'e') {
			if (current_index > 0) {
				cout << "0" << '\n';
			}
			else {
				cout << "1" << '\n';
			}
		}
	}

	return 0;
}