#include <iostream>

using namespace std;

int min_v = 64;
int map[51][51];

void find_match(int y, int x) {
	int w_w_c = 0;
	int w_b_c = 0;
	int h_w_c = 0;
	int h_b_c = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (map[i][j] == 1) {
					w_w_c++;
				}
				else {
					w_b_c++;
				}
			}
			else {
				if (map[i][j] == 1) {
					h_w_c++;
				}
				else {
					h_b_c++;
				}
			}
		}
	}
	int w_c = abs(32 - w_w_c) + abs(32 - h_b_c);
	int h_c = abs(32 - h_w_c) + abs(32 - w_b_c);

	if (min_v > h_c) {
		min_v = h_c;
	}
	if (min_v > w_c) {
		min_v = w_c;
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	char temp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == 'W') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 8 <= n) {
				if (j + 8 <= m) {
					find_match(i, j);
				}
			}
		}
	}

	cout << min_v;

	return 0;
}