#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, ans;
int a[20][20];
queue<int> q;

void get(int i, int j) {
	if (a[i][j]) {
		q.push(a[i][j]);
		a[i][j] = 0;
	}
}

void merge(int i, int j, int di, int dj) {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (!a[i][j]) a[i][j] = x;
		else if (a[i][j] == x) {
			a[i][j] = x * 2;
			i += di, j += dj;
		}
		else {
			i += di, j += dj;
			a[i][j] = x;
		}
	}
}

void move(int k) {
	if (k == 0) {
		// Up
		for (int j = 0; j<n; j++) {
			for (int i = 0; i<n; i++) get(i, j);
			merge(0, j, 1, 0);
		}
	}
	else if (k == 1) {
		// Down
		for (int j = 0; j<n; j++) {
			for (int i = n - 1; i >= 0; i--) get(i, j);
			merge(n - 1, j, -1, 0);
		}
	}
	else if (k == 2) {
		// Left
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) get(i, j);
			merge(i, 0, 0, 1);
		}
	}
	else {
		// Right
		for (int i = 0; i<n; i++) {
			for (int j = n - 1; j >= 0; j--) get(i, j);
			merge(i, n - 1, 0, -1);
		}
	}
}

void solve(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (ans < a[i][j]) ans = a[i][j];
			}
		}
		return;
	}
	int b[20][20];
	memcpy(b, a, sizeof(a));
	for (int k = 0; k<4; k++) {
		move(k);
		solve(cnt + 1);
		memcpy(a, b, sizeof(b));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}