#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int tc;
int count_n;
int arr_input[501];

priority_queue <int, vector<int>, greater<int>> pq;

int get_min(int input_a, int input_b) {
	return input_a > input_b ? input_b : input_a;
}

int dp[501] = { 0, };
int temp;
int temp_a, temp_b;
int result = 0;

int main() {

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> count_n;
		for (int j = 0; j < count_n; j++) {
			cin >> temp;
			arr_input[j] = temp;
			pq.push(temp);
		}
;

		while (pq.size() > 1) {
			temp_a = pq.top();
			pq.pop();
			temp_b = pq.top();
			pq.pop();
			pq.push(temp_a + temp_b);

			result += temp_a + temp_b;
			cout << "temp_a : " << temp_a << ", temp_b : " << temp_b << '\n';
			cout << result << '\n';
		}
		cout << result << '\n';
		result = 0;
	}

	return 0;
}