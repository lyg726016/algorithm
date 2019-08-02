#include <iostream>

using namespace std;

int input_n;
//1~input_m
int input_m;

int *result_value;

void print_result(int start_index, int count_left) {
	if (count_left <= 0) {
		for (int i = 0; i < input_n; i++) {
			cout << result_value[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = start_index; i <= input_n; i++) {
		result_value[input_m - count_left] = i;
		print_result(i, count_left - 1);
	}
}

int main() {

	cin >> input_n >> input_m;
	result_value = new int[input_m + 1];

	print_result(1, input_m);


	return 0;
}