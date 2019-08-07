#include <iostream>
#include <math.h>

using namespace std;

int input_num;
int result_set[1000001];

int get_min(int input_a, int input_b) {
	return input_a < input_b ? input_a : input_b;
}

int main() {
	
	cin >> input_num;

	result_set[0] = 0;
	result_set[1] = 0;

	for (int i = 2; i <= input_num; i++) {
		result_set[i] = result_set[i - 1] + 1;
		if (i % 2 == 0) {
			result_set[i] = get_min(result_set[i / 2] + 1, result_set[i]);
		}
		if (i % 3 == 0) {
			result_set[i] = get_min(result_set[i / 3] + 1, result_set[i]);
		}
	}

	cout << result_set[input_num];

	return 0;
}