#include <iostream>

using namespace std;

int input_a, input_b;

int main() {
	cin >> input_a >> input_b;

	int up = 1;
	int down = 1;

	for (int i = 0; i < input_b; i++) {
		up *= (input_a - i);
	}
	for (int i = 0; i < input_b; i++) {
		down *= (input_b - i);
	}
	if (down == 0) {
		down = 1;
	}
	cout << up / down;

	return 0;
}