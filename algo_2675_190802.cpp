#include <iostream>

using namespace std;

int count_input;
int count_print;
int current_index;

int main() {

	cin >> count_input;

	for (int i = 0; i < count_input; i++) {
		cin >> count_print;
		char input_char[20] = "";
		cin >> input_char;
		current_index = 0;

		while (input_char[current_index] != '\0') {
			for (int j = 0; j < count_print; j++) {
				cout << input_char[current_index];
			}
			current_index++;
		}
		cout << '\n';
	}

	return 0;
}