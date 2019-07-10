#include <iostream>
#include <queue>
#include <Windows.h>


//LEFT -1, RIGHT +1
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

#define NONE 0
#define SNAKE 1
#define APPLE 2

#define TURN_LEFT 1
#define TURN_RIGHT 2

#define MAX_BOARD 101
#define MAX_SECONDS 10001


using namespace std;

queue<pair<int, int>> snake;

int size_of_board = 0;
int count_apple = 0;
int current_direction = 0;
int count_direction = 0;

int x = 0, y = 0;
int map[MAX_BOARD][MAX_BOARD];
int direction[MAX_SECONDS];
int apple_x = 0, apple_y = 0;
int time = 0;
char input_direction;


void show() {
	Sleep(300);
	int N = size_of_board;
	system("cls");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



int main()
{

	for (int i = 0; i < MAX_BOARD; i++) {
		for (int j = 0; j < MAX_BOARD; j++) {
			map[i][j] = NONE;
		}
		direction[i] = 0;
	}

	cin >> size_of_board;


	cin >> count_apple;

	for (int i = 0; i < count_apple; i++) {
		cin >> apple_y >> apple_x;
		map[apple_y - 1][apple_x - 1] = APPLE;
	}


	cin >> count_direction;

	for (int i = 0; i < count_direction; i++) {
		cin >> time;
		cin >> input_direction;
		if (input_direction == 'L') {
			direction[time] = TURN_LEFT;
		}
		else {
			direction[time] = TURN_RIGHT;
		}
	}

	time = 1;
	map[y][x] = SNAKE;
	snake.push(make_pair(y, x));

	while (true) {
		if (current_direction == RIGHT) x++;
		if (current_direction == DOWN) y++;
		if (current_direction == LEFT) x--;
		if (current_direction == UP) y--;


		if (x < 0 || y < 0 || x >= size_of_board || y >= size_of_board) {
			printf("%d", time);
			scanf_s("%d", &time);
			return 0;
		}

		if (map[y][x] == APPLE) {
			snake.push(make_pair(y, x));
		}
		else if (map[y][x] == SNAKE) {
			printf("%d", time);
			scanf_s("%d", &time);
			return 0;
		}
		else {
			if (!snake.empty()) {
				map[snake.front().first][snake.front().second] = NONE;
				snake.pop();
			}
			snake.push(make_pair(y, x));
		}

		map[y][x] = SNAKE;

		if (direction[time] == TURN_LEFT)
			current_direction = (current_direction - 1);
		if (direction[time] == TURN_RIGHT)
			current_direction = (current_direction + 1) % 4;

		if (current_direction < 0) {
			current_direction = UP;
		}

		show();
		time++;
	}
}