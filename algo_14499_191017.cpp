#include <cstdio>

int n, m, x, y, k;
int a[20][20];
int dice[6], temp[6];
const int direct[4][6] = {
	{ 2, 1, 5, 0, 4, 3 },
	{ 3, 1, 0, 5, 4, 2 },
	{ 4, 0, 2, 3, 5, 1 },
	{ 1, 5, 2, 3, 0, 4 }
};
const int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };

void solve() {
	while (k--) {
		int d;
		scanf("%d", &d); d--;
		x += dx[d], y += dy[d];
		if (x < 0 || x >= n || y < 0 || y >= m) {
			x -= dx[d], y -= dy[d];
			continue;
		}
		for (int i = 0; i<6; i++) {
			temp[i] = dice[i];
		}
		for (int i = 0; i<6; i++) {
			dice[i] = temp[direct[d][i]];
		}
		if (a[x][y]) {
			dice[5] = a[x][y];
			a[x][y] = 0;
		}
		else {
			a[x][y] = dice[5];
		}
		printf("%d\n", dice[0]);
	}
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve();
	return 0;
}


ÃâÃ³: https ://rebas.kr/784 [PROJECT REBAS]