#include <cstdio>
#include <vector>
using namespace std;

struct cctv {
	int x, y, id;
};

int n, m, ans = 1e9;
int a[10][10], b[10][10];
vector<cctv> v;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
const int U = 1, R = 1 << 1, D = 1 << 2, L = 1 << 3;
vector<int> direct[6] = { {},
{ U, R, D, L }, // CCTV 1 : One direction
{ U | D, R | L },   // CCTV 2 : Two direction (180 degree)
{ U | R, R | D, D | L, L | U },         // CCTV 3 : Two direction (90 degree)
{ L | U | R, U | R | D, R | D | L, D | L | U }, // CCTV 4 : Three direction
{ U | R | D | L } };   // CCTV 5 : Four direction

void observe(int x, int y, int i, int d) {
	// CCTV observation. d==1(On), d==-1(off)
	for (int k = 0; k<4; k++) {
		if (i & (1 << k)) {
			int nx = x, ny = y;
			while (a[nx][ny] != 6) {
				b[nx][ny] += d;
				nx += dx[k], ny += dy[k];
			}
		}
	}
}

void solve(int index) {
	if (index == (int)v.size()) {
		// Count blind areas.
		int area = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (b[i][j] == 0) area += 1;
			}
		}
		if (ans > area) ans = area;
		return;
	}
	int x = v[index].x, y = v[index].y, id = v[index].id;
	for (auto i : direct[id]) {
		observe(x, y, i, 1);  // Turn on cctv.
		solve(index + 1);
		observe(x, y, i, -1); // Turn off cctv.
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n + 2; i++) {
		for (int j = 0; j<m + 2; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) a[i][j] = 6;
			else {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 6) b[i][j] = 1;
				else if (a[i][j] != 0) v.push_back({ i, j, a[i][j] });
			}
		}
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}