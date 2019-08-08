#include <iostream>

using namespace std;

int input_n;
int arr_input[1000];
int dp[1000];

int main() {
	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		cin >> arr_input[i];
	}


	for (int i = 0; i < input_n; i++) {
		if (dp[i] == 0)
			dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr_input[i] > arr_input[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	int max_v = 0;
	for (int i = 0; i < input_n; i++) {
		if (dp[i] > max_v) {
			max_v = dp[i];
		}
	}

	cout << max_v;

	return 0;
}