#include <iostream>
using namespace std;

int arr[510][2];
int dp[510][510];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i < n; i++) {
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int m = 2; m <= n; m++) { //Â÷
		for (int i = 1; i <= n - m; i++) { //½ÃÀÛ
			int j = i + m;
			for (int k = i; k < j; k++)  {
				int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (!dp[i][j] || dp[i][j] > res) dp[i][j] = res;
			}
		}
	}
	cout << dp[1][n];
	return 0;
}