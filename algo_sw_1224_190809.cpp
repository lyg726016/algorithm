#include <iostream>

using namespace std;

int length_input;
char* input_string;

int main() {

	for (int i = 0; i < 10; i++) {
		cin >> length_input;
		cin >> input_string;

		cout << input_string;
	}

	return 0;
}