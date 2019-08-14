#include <iostream>

using namespace std;

#define NOT_CLEAN 0
#define WALL 1
#define CLEAN 2
#define UPPER 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define MAX_ROTATION 4

#define MAX_SIZE 50

int clean_count = 0;
int input_array[MAX_SIZE][MAX_SIZE];
int rotation_count = 0;
bool is_first = true;

void clean(int x, int y) {
	if (input_array[y][x] == NOT_CLEAN) {
		input_array[y][x] = CLEAN;
		clean_count++;
	}
}

int main()
{

	//input
	int array_y, array_x;
	int x, y, direction;

	cin >> array_y >> array_x;
	cin >> y >> x >> direction;

	//input
	for (int i = 0; i < array_y; i++) {
		for (int j = 0; j < array_x; j++) {
			scanf_s("%d", &input_array[i][j]);
		}
	}

	
	//solution
	//rotation, clean, move
	while (true) {
		//is first -> clean
		if (is_first) {
			clean(x, y);
			is_first = false;
		}
		//2 - a, b ( search, clean, rotation)
		//if rotation_count == 4 -> end search, clean
		while (rotation_count < MAX_ROTATION) {
			//direction
			switch (direction)
			{
			case 0:
				if (input_array[y][x - 1] == NOT_CLEAN) {
					clean(--x, y);
					direction = 3;
					rotation_count = 0;
				}
				else {
					direction = 3;
					rotation_count++;
				}
				break;

			case 1:
				if (input_array[y - 1][x] == NOT_CLEAN) {
					clean(x, --y);
					direction = 0;
					rotation_count = 0;
				}
				else {
					direction = 0;
					rotation_count++;
				}
				break;

			case 2:
				if (input_array[y][x + 1] == NOT_CLEAN) {
					clean(++x, y);
					direction = 1;
					rotation_count = 0;
				}
				else {
					direction = 1;
					rotation_count++;
				}
				break;

			case 3:
				if (input_array[y + 1][x] == NOT_CLEAN) {
					clean(x, ++y);
					direction = 2;
					rotation_count = 0;
				}
				else {
					direction = 2;
					rotation_count++;
				}
				break;
			}
		}

		//2 - c, d (move)
		//if rotation_count == 4 -> move, end
		rotation_count = 0;
		switch (direction)
		{
		case 0:
			//if wall -> return
			if (input_array[y + 1][x] == WALL) {
				printf("%d", clean_count);
				return 0;
			}
			else {
				//move
				y++;
			}
			break;

		case 1:
			//if wall -> return
			if (input_array[y][x - 1] == WALL) {
				printf("%d", clean_count);
				return 0;
			}
			else {
				//move
				x--;
			}
			break;

		case 2:
			//if wall -> return
			if (input_array[y - 1][x] == WALL) {
				printf("%d", clean_count);
				return 0;
			}
			else {
				//move
				y--;
			}
			break;

		case 3:
			//if wall -> return
			if (input_array[y][x + 1] == WALL) {
				printf("%d", clean_count);
				return 0;
			}
			else {
				//move
				x++;
			}
			break;
		}
	}
	return 0;
}