#include <iostream>
#include <cstring>
#include <math.h>

#define DIRECTION 4
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

#define REAL_RIGHT 0
#define REAL_DOWN 1
#define REAL_LEFT 2
#define REAL_UP 3

#define MAX_X 101
#define MAX_Y 101

using namespace std;

int map[MAX_Y][MAX_X];
int count_squar = 0;
int direction_array_size;

int* make_dircetion_array(int g, int * direction_array, int direction_array_size) {

	if (g == 0) {
		return direction_array;
	}
	int * current_direction_array = (int *)malloc(sizeof(int) * (direction_array_size * 2));

	for (int i = 0; i < direction_array_size; i++) {
		current_direction_array[i] = direction_array[i];
		current_direction_array[direction_array_size + i] = (direction_array[direction_array_size - i - 1] + 1) % 4;
	}

	free(direction_array);
	make_dircetion_array(g - 1, current_direction_array, direction_array_size * 2);
}


void draw_line(int x, int y, int g, int * direction_array) {
	for (int i = 0; i < pow(2, g); i++) {
		switch (direction_array[i])
		{
		case RIGHT:
			map[y][x + 1] = 1;
			x++;
			break;

		case LEFT:
			map[y][x - 1] = 1;
			x--;
			break;

		case UP:
			map[y - 1][x] = 1;
			y--;
			break;

		case DOWN:
			map[y + 1][x] = 1;
			y++;
			break;
		}
	}
}

void cal_count_square() {
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			if (map[y][x] == 1 && map[y][x + 1] == 1 && map[y + 1][x + 1] == 1 && map[y + 1][x] == 1) {
				count_squar++;
			}
		}
	}
	printf("%d", count_squar);
}

int main()
{
	int test_case;
	int T;
	cin >> T;
	int x, y, d, g;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		int * initial_direction_array = (int *)malloc(sizeof(int) * 1);
		initial_direction_array[0] = d;
		int * direction_array = make_dircetion_array(g, initial_direction_array, 1);
		draw_line(x, y, g, direction_array);
	}

	cal_count_square();
	return 0;
}