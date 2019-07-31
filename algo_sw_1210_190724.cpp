//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh&categoryId=AV14ABYKADACFAYh&categoryType=CODE

#include <iostream>
#include <queue>

using namespace std;

#define TC 10
#define SIZE 100

int **map;
int test_number;
int input_a;

pair <int, int> current_point;


int main() {

	map = new int*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		map[i] = new int[SIZE];
	}

	for (int i = 0; i < TC; i++) {
		cin >> test_number;

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				scanf("%d", &input_a);
				map[i][j] = input_a;
				//find destination point
				if (input_a == 2) {
					current_point = make_pair(i, j);
				}

			}
		}

		//set destination point
		//current_point;

		//find start point
		while (true) {
			//start point
			if (current_point.first == 0) {
				cout << "#" << test_number << " " << current_point.second << endl;
				break;
			}

			//left possible -> move left
			if (current_point.second > 0 && (map[current_point.first][current_point.second - 1] == 1)) {
				current_point = make_pair(current_point.first, current_point.second - 1);
			}
			//right possible -> move right
			else if (current_point.second < SIZE - 1 && (map[current_point.first][current_point.second + 1] == 1)) {
				current_point = make_pair(current_point.first, current_point.second + 1);
			}
			else {
				//else -> move up
				current_point = make_pair(current_point.first - 1, current_point.second);
			}
			//remove back
			map[current_point.first][current_point.second] = 0;
		}
	}

	for (int i = 0; i < SIZE; i++) {
		delete[] map[i];
	}
	delete[] map;

	return 0;
}
