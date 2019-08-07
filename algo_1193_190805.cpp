#include <iostream>

using namespace std;

int sum_arr[5001];
int input_a;
int line_v;
int temp_result;
int result_c;
int result_m;

int main() {

	cin >> input_a;

	for (int i = 1; i < 5001; i++) {
		sum_arr[i] = sum_arr[i - 1] + i;
		if (input_a <= sum_arr[i]) {
			line_v = i;
			break;
		}
	}

	//몇번째
	temp_result = input_a - sum_arr[line_v - 1];

	if (line_v == 1) {
		cout << "1/1";
		return 0;
	}

	//방향
	if (line_v % 2 == 0) {
		result_c = temp_result;
		result_m = line_v - temp_result + 1;
	}
	else {
		result_c = line_v - temp_result + 1;
		result_m = temp_result;
	}



	cout << result_c << "/" << result_m << '\n';

	return 0;
}