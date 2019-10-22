#include <cstdio>

int n, m, h, ans = 4;
bool a[30][10];

bool ladder() {
	for (int i = 0; i<n; i++) {
		int k = i;
		for (int j = 0; j<h; j++) {
			if (a[j][k]) k += 1;
			else if (k > 0 && a[j][k - 1]) k -= 1;
		}
		if (i != k) return false;
	}
	return true;
}

void solve(int cnt, int x, int y) {
	if (ans <= cnt) return;
	if (ladder()) {
		if (ans > cnt) ans = cnt;
		return;
	}
	if (cnt == 3) return;
	for (int i = x; i<h; i++, y = 0) {
		for (int j = y; j<n - 1; j++) {
			if (a[i][j]) {
				j += 1;
			}
			else {
				a[i][j] = 1;
				solve(cnt + 1, i, j + 2);
				a[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x - 1][y - 1] = 1;
	}
	solve(0, 0, 0);
	printf("%d\n", ans < 4 ? ans : -1);
	return 0;
}