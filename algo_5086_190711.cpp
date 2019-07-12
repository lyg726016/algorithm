#include <iostream>

using namespace std;

#define FACTOR 1
#define MULTIPLE 2
#define NEITHER 3

int result[10000];


int main() {

	for (int i = 0; i < 10000; i++) {
		result[i] = 0;
	}

	int input_a = 1, input_b = 1;
	int i = 0;

	while (true) {

		cin >> input_a >> input_b;

		if (input_a != 0 && input_b != 0) {
			if (input_a > input_b) {
				if ((input_b != 0) && (input_a % input_b) == 0) {
					result[i] = 2;
				}
				else {
					result[i] = 3;
				}
			}
			else {
				if ((input_a != 0) && (input_b % input_a) == 0) {
					result[i] = 1;
				}
				else {
					result[i] = 3;
				}
			}
			i++;
		}
		else {
			break;
		}
	}

	for (int j = 0; j <= i; j++) {
		if (result[j] == FACTOR) {
			cout << "factor" << endl;
		}
		if (result[j] == MULTIPLE) {
			cout << "multiple" << endl;
		}
		if (result[j] == NEITHER) {
			cout << "neither" << endl;
		}
	}

	return 0;
}