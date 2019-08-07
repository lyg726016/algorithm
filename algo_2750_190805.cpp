#include <iostream>

using namespace std;

int count_input;
int arr_input[1000];
int arr_result[1000];
int max_v = 1;
int max_i = 1001;
int result_count = 0;

int main() {

	cin >> count_input;

	for (int i = 0; i < count_input; i++) {
		cin >> arr_input[i];
	}

	result_count = count_input -1;

	while (result_count + 1)
	{
		max_v = -1001;
		for (int i = 0; i < count_input; i++) {
			if (arr_input[i] > max_v) {
				max_v = arr_input[i];
				max_i = i;
			}
		}
		arr_result[result_count] = max_v;
		arr_input[max_i] = -1001;
		result_count--;
	}
	for (int i = 0; i < count_input; i++) {
		cout << arr_result[i] << '\n';
	}

	return 0;
}