#include <iostream>
#include <cstring>
using namespace std;

int input_n;

bool map[16][16] = { 0, };
int result = 0;


int dir[8][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ 1,1 },{ 1,-1 },{ -1,0 },{ -1,1 },{ -1,-1 } };

void showMap() {
	for (int i = 1; i <= input_n; i++) {
		for (int j = 1; j <= input_n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}


void check_map(int y, int x) {
	for (int i = 1; i <= input_n; i++) {
		map[y][i] = 1;
		map[i][x] = 1;

		if (y - i >= 1 && x + i <= input_n) {
			map[y - i][x + i] = 1;
		}
		if (y - i >= 1 && x - i >= 1) {
			map[y - i][x - i] = 1;
		}
		if (y + i <= input_n && x + i <= input_n) {
			map[y + i][x + i] = 1;
		}
		if (y + i <= input_n && x - i >= 1) {
			map[y + i][x - i] = 1;
		}
	}
}

void solve(int y, int count_q) {
	if (count_q == input_n) {
		result++;
		return;
	}

	bool cpy_map[16][16] = { 0, };

	memcpy(cpy_map, map, sizeof(map));

	for (int i = 1; i <= input_n; i++) {
		if (!map[y][i]) {
			map[y][i] = 1;
			check_map(y, i);
			solve(y + 1, count_q + 1);
			memcpy(map, cpy_map, sizeof(map));
		}
	}

}


int main() {

	cin >> input_n;

	solve(1, 0);

	cout << result;
	return 0;
}