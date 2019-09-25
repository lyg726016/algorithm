#include <iostream>

using namespace std;

int n, m;

long long result[31][31] = { 0, };

void solve() {
	for (int i = 1; i < 31; i++) {
		result[1][i] = i;
	}
	
	for (int i = 1; i < 31; i++) {
		for (int j = 1; j < 31; j++) {
			if (i == 1 && j == 1) {
				result[i][j] = 1;
			}
			else {
				if (j == 1) {
					result[1][i] = i;
				}
				else {
					result[j][i] = result[j - 1][i - 1] + result[j][i - 1];
				}
			}
		}
	}
}

int main()
{
	int tc;
	cin >> tc;


	solve();


	for (int i = 0; i < tc; i++) {
		cin >> n >> m;

		if (n == 0 || m == 0) {
			cout << 0 << '\n';
			continue;
		}

		cout << result[n][m] << '\n';
	}
	return 0;
}