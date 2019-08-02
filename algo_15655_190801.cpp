#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <int> input_vector;
bool *is_used;
int * result_arr;
int * input_arr;

void func(int current_index, int k) {
	if (k == m) { // 현재 k개까지 수를 택했음.
		for (int i = 0; i < m; i++) {
			cout << result_arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = current_index; i < n; i++) {
		if (is_used[i] == false) {
			result_arr[k] = input_arr[i];
			is_used[i] = true;
			func(i, k + 1);
			is_used[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;

	int temp_input;

	for (int i = 0; i < n; i++) {
		cin >> temp_input;
		input_vector.push_back(temp_input);
	}

	sort(input_vector.begin(), input_vector.end());

	is_used = new bool[n];
	for (int i = 0; i < n; i++) is_used[i] = false;

	result_arr = new int[n];
	input_arr = new int[n];

	for (int i = 0; i < n; i++) {
		input_arr[i] = input_vector.at(i);
	}

	func(0, 0);

	return 0;
}