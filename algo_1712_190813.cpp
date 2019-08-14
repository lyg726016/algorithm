#include <iostream>

using namespace std;

long long input_a, input_b, input_c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> input_a >> input_b >> input_c;

	int count = 0;

	int result = (input_a) / (input_c - input_b);
	result++;

	if (input_c <= input_b) {
		cout << -1;
	}
	else {
		cout << result;
	}
	return 0;
}