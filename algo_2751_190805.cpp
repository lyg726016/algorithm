#include <iostream>
#include <algorithm>

using namespace std;

int count_input;
int * arr_input;

int main() {
	cin >> count_input;

	arr_input = new int[count_input];

	for (int i = 0; i < count_input; i++) {
		cin >> arr_input[i];
	}

	sort(arr_input, arr_input + count_input);

	for (int i = 0; i < count_input; i++) {
		cout << arr_input[i] << '\n';
	}

	return 0;
}