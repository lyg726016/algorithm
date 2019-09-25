#include <iostream>

using namespace std;

int result = 0;
int n, m;

void solve(int c_c, int c_i) {
	if (c_c == n) {
		result++;
		return;
	}
	else {
		if (c_i >= n) {
			return;
		}
	}

	if (c_i >= n) {
		return;
	}
	

	for (int i = c_i; i < n; i++) {
		for (int j = i; j < m; j++) {
			//넣는
			solve(c_c + 1, c_i + 1);
			//안넣는
			solve(c_c, c_i + 1);
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	

	for (int i = 0; i < tc; i++) {
		cin >> n >> m;
		result = 0;
		
		solve(0, 0);
		cout << result << '\n';
	}


	return 0;
}