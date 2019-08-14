#include <iostream>

using namespace std;

int input_a, input_b, input_c;

int main() {

	while (true) {
		cin >> input_a >> input_b >> input_c;
		long long input_a_s = input_a * input_a;
		long long input_b_s = input_b * input_b;
		long long input_c_s = input_c * input_c;

		if (input_a == 0 && input_b == 0 && input_c == 0)
			return 0;

		if ((input_a_s == (input_b_s + input_c_s)) ||
			(input_b_s == (input_a_s + input_c_s)) ||
			(input_c_s == (input_a_s + input_b_s))) {
			cout << "right";
		}
		else {
			cout << "wrong";
		}

			cout << '\n';
	}


	return 0;
}