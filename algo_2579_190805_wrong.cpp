#include <iostream>

using namespace std;

int input_n;
int arr_input[10001];
int arr_result[10001][3];

int get_max(int input_a, int input_b) {
	return input_a > input_b ? input_a : input_b;
}


int main() {

	cin >> input_n;

	for (int i = 1; i <= input_n; i++) {
		cin >> arr_input[i];
	}

	arr_result[1][0] = 0 + 0;
	arr_result[1][1] = arr_input[1];
	arr_result[1][2] = 0 + arr_input[1];

	arr_result[2][0] = arr_input[1];
	arr_result[2][1] = arr_input[2];
	arr_result[2][2] = arr_input[1] + arr_input[2];

	for (int i = 3; i <= input_n; i++) {
		arr_result[i][0] = get_max(get_max(arr_result[i - 1][2], arr_result[i - 1][1]), arr_result[i - 1][0]);
		arr_result[i][1] = arr_result[i - 1][0] + arr_input[i];
		arr_result[i][2] = arr_result[i - 1][1] + arr_input[i];

		if (i == input_n - 1) {
			arr_result[i][2] = 0;
		}
	}

	int result = get_max(arr_result[input_n][1], arr_result[input_n][2]);

	cout << result;

	return 0;
}