#include <iostream>

using namespace std;

int input_a;
int count_ = 0;
int temp;
int tlq, dlf;
int main() {
	cin >> input_a;
	temp = input_a;

	while (true) {
		count_++;
		tlq = temp / 10;
		dlf = temp - tlq * 10;

		temp = tlq + dlf;
		temp = temp - ((temp / 10) * 10);

		temp = dlf * 10 + temp;

		//cout << temp << '\n';

		if (temp == input_a) {
			cout << count_;
			return 0;
		}
	}

	return 0;
}