#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 15
int N;
int case_cnt = 0;

bool map[MAX_N + 1][MAX_N + 1] = { 0, };
int dir[8][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ 1,1 },{ 1,-1 },{ -1,0 },{ -1,1 },{ -1,-1 } };

bool map[MAX_N + 1][MAX_N + 1] = { 0, };
void showMap(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}


void set(int y, int x) {
	map[y][x] = true;

	for (int i = 0; i < 8; i++) {
		int c_x = x;
		int c_y = y;
		while (true) {
			y += dir[i][0];
			x += dir[i][1];
			if (y >= N || x >= N || x < 0 || y < 0)break;
			map[y][x] = true;
		}
		x = c_x;
		y = c_y;
	}
}

void queen(int y, int x, int cnt) {
	if (cnt == N) {
		case_cnt++;
		return;
	}

	bool cpy_map[MAX_N + 1][MAX_N + 1] = { 0, };
	memcpy(cpy_map, map, sizeof(map));
	set(y, x);

	for (int j = 0; j < N; j++) {
		if (!map[y + 1][j]) {
			queen(y + 1, j, cnt + 1);
		}
	}
	memcpy(map, cpy_map, sizeof(map));
}


int main() {
	// your code goes here

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		queen(0, i, 1);
	}
	printf("%d", case_cnt);
	return 0;
}