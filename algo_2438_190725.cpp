#include <iostream>

using namespace std;

int input_count;

int main() {

	cin >> input_count;
	for (int i = 0; i < input_count; i++) {
		for (int k = 1; k < input_count - i; k++) {
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}