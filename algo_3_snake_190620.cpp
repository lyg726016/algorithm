#include <iostream>
#include <vector>
#include <queue>
#include <Windows.h>

using namespace std;

#define MAX_SIZE 100 + 1
#define MAX_X 10000 + 1

#define EMPTY 0
#define SNAKE 1
#define APPLE 2

#define U 0
#define R 1
#define D 2
#define L 3

int N, K, M;
int map[MAX_SIZE][MAX_SIZE] = { 0, };
char turn[MAX_X] = { 0, };
queue<pair<int, int>> snake;

void show() {
	Sleep(1000);
	system("cls");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {

	scanf_s("%d", &N);

	scanf_s("%d", &K);

	int x, y;

	for (int i = 0; i < K; i++) {
		scanf_s("%d %d", &y, &x);
		map[y - 1][x - 1] = APPLE;
	}

	//apple
	scanf_s("%d", &M);

	for (int i = 0; i < M; i++) {
		int X;
		char C;
		scanf_s("%d %c", &X, &C);
		turn[X] = C;
		//printf("%c\n",turn[X]);
	}

	int second = 0;
	int T = R;
	y = 0;
	x = 0;
	snake.push(make_pair(y, x));
	map[y][x] = SNAKE;


	while (1) {
		show();

		int bfr_y = y;
		int bfr_x = x;

		if (T == U) y--;
		if (T == R) x++;
		if (T == D) y++;
		if (T == L) x--;

		if (x < 0 || x >= N || y < 0 || y >= N || map[y][x] == 1) {
			//printf("%d %d %d %d",bfr_y,bfr_x,y,x);
			break;
		}

		if (map[y][x] != APPLE) {
			pair<int, int> p = snake.front();
			snake.pop();
			map[p.first][p.second] = EMPTY;
		}

		snake.push(make_pair(y, x));
		map[y][x] = SNAKE;

		second++;

		if (turn[second] == 'L') T--;
		if (turn[second] == 'D') T++;

		if (T < 0) T = L;
		if (T > 3) T = U;
	}

	printf("%d", second + 1);
	scanf_s("%d", &second);
	return 0;
}