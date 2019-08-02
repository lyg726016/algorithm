#include <iostream>
#include <queue>

using namespace std;

int **map;
int count_q;
int input_n;
int total_count = 0;

#define ATTACKED_Q 1
#define LOCATE_Q 2
#define NOT 3


queue<int, int> location_q;


void solve(int number_q) {
	if (number_q == count_q) {
		total_count++;
		reset_map();
		return;
	}

	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			if (map[i][j] == NOT) {
				marking_map(i, j);
				solve(number_q++);
			}
			else if (map[i][j] = ATTACKED_Q) {
				continue;
			}
			else if (map[i][j] = LOCATE_Q) {
				continue;
			}
			else {

			}
		}
	}
}

void marking_map(int x, int y) {
	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			//세로
			if (i ==  y) {
				map[i][j] = 1;
			}
			//가로
			if (j == x) {
				map[i][j] = 1;
			}
			//대각선
		}
	}
}

void reset_map() {
	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			map[i][j] = 0;
		}
	}
}

int main() {

	cin >> input_n;

	count_q = input_n;

	map = new int*[input_n];
	for (int i = 0; i < input_n; i++)
		map[i] = new int[input_n];

	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			map[i][j] = 0;
		}
	}

	solve(0);
	return 0;
}