#include <iostream>

using namespace std;

int less_dp[1001];
int greater_dp[1001];
int input_n;
int arr_input[1001];

int main() {
	cin >> input_n;
	for (int i = 0; i < input_n; i++) {
		cin >> arr_input[i];
	}

	for (int i = 0; i < input_n; i++) {
		if (greater_dp[i] == 0) {
			greater_dp[i] = 1;
		}
		for (int j = 0; j < i; j++) {
			if (arr_input[i] > arr_input[j]) {
				if (greater_dp[i] <= greater_dp[j]) {
					greater_dp[i] = greater_dp[j] + 1;
				}
			}
		}
	}

	for (int i = input_n - 1; i >= 0; i--) {
		if (less_dp[i] == 0) {
			less_dp[i] = 1;
		}
		for (int j = input_n - 1; j > i; j--) {
			if (arr_input[i] > arr_input[j]) {
				if (less_dp[i] <= less_dp[j]) {
					less_dp[i] = less_dp[j] + 1;
				}
			}
		}
	}

	int sum;
	int max_v = 0;
	for (int i = 0; i < input_n; i++) {
		sum = greater_dp[i] + less_dp[i];
		if (sum > max_v) max_v = sum;
	}

	cout << max_v -1;

	return 0;
}