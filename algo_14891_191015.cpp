#include<iostream>
#include<vector>
#include<string>

int a[4][8];
int k, ans;

void rotate(int n, int d) {
	int t[8];
	if (d == 1) {
		for (int i = 0; i<8; i++) {
			t[(i + 1) % 8] = a[n][i];
		}
	}
	else {
		for (int i = 0; i<8; i++) {
			t[i] = a[n][(i + 1) % 8];
		}
	}
	for (int i = 0; i<8; i++) {
		a[n][i] = t[i];
	}
}

void solve() {
	while (k--) {
		int n, d;
		scanf("%d %d", &n, &d); n--;
		int direct[4] = { 0 };
		direct[n] = d;
		for (int i = n; i<3; i++) {
			if (a[i][2] != a[i + 1][6]) direct[i + 1] = -direct[i];
		}
		for (int i = n; i>0; i--) {
			if (a[i][6] != a[i - 1][2]) direct[i - 1] = -direct[i];
		}
		for (int i = 0; i<4; i++) {
			if (direct[i]) {
				rotate(i, direct[i]);
			}
		}
	}
}

int main() {
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<8; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	scanf("%d", &k);
	solve();
	for (int i = 0; i<4; i++) {
		if (a[i][0]) ans += (1 << i);
	}
	printf("%d\n", ans);
	return 0;
}
