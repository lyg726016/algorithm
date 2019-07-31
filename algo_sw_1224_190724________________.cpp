#include <iostream>

using namespace std;

#define TC 10

int count_input;
char *input_c;

int main() {

	for (int i = 0; i < TC; i++) {
		cin >> count_input;
		input_c = new char(count_input);

		for (int j = 0; j < count_input; j++) {
			cin >> input_c[j];
		}
	}


	return 0;
}