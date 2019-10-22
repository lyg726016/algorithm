#include <iostream>

using namespace std;

#define MAX_Y 500 + 1
#define MAX_X 500 + 1

int y = 0;
int x = 0;
//a = 원 입력
int input_array_a[MAX_Y][MAX_X];
//상하 반전
int input_array_b[MAX_Y][MAX_X];
//좌우 반전
int input_array_c[MAX_Y][MAX_X];

int temp = 0;
int result_max = 0;

int get_max(int input_a, int input_b) {
	return input_a >= input_b ? input_a : input_b;
}

int main() {

	cin >> y >> x;

	for (int a = 0; a < MAX_Y; a++) {
		for (int b = 0; b < MAX_X; b++) {
			input_array_a[a][b] = 0;
		}
	}


	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> input_array_a[i][j];
			input_array_b[y - i][j] = input_array_a[i][j];
			input_array_c[i][x - j] = input_array_a[i][j];
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			//blue
			if (i + 3 <= y) {
				temp = input_array_a[i][j] + input_array_a[i + 1][j] + input_array_a[i + 2][j] + input_array_a[i + 3][j];
				result_max = get_max(temp, result_max);
			}

			if (j + 3 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i][j + 2] + input_array_a[i][j + 3];
				result_max = get_max(temp, result_max);
			}

			//green
			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_a[i][j] + input_array_a[i + 1][j] + input_array_a[i + 1][j + 1] + input_array_a[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i - 1][j + 1] + input_array_a[i - 1][j + 2];
				result_max = get_max(temp, result_max);
			}

			//yellow
			if (i + 1 <= y && j + 1 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i + 1][j] + input_array_a[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			//orange
			if (i + 1 <= y && j + 2 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i][j + 2] + input_array_a[i + 1][j];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i + 1][j + 1] + input_array_a[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_a[i][j] + input_array_a[i + 1][j] + input_array_a[i + 2][j] + input_array_a[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i][j + 2] + input_array_a[i - 1][j + 2];
				result_max = get_max(temp, result_max);
			}

			//pink

			if (i + 2 <= y && j - 1 >= 1 && j - 1 <= x) {
				temp = input_array_a[i][j] + input_array_a[i + 1][j] + input_array_a[i + 2][j] + input_array_a[i + 1][j - 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i][j + 2] + input_array_a[i - 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_a[i][j] + input_array_a[i + 1][j] + input_array_a[i + 2][j] + input_array_a[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 1 <= y && j + 2 <= x) {
				temp = input_array_a[i][j] + input_array_a[i][j + 1] + input_array_a[i][j + 2] + input_array_a[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}
		}
	}

	//상하
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			//blue
			if (i + 3 <= y) {
				temp = input_array_b[i][j] + input_array_b[i + 1][j] + input_array_b[i + 2][j] + input_array_b[i + 3][j];
				result_max = get_max(temp, result_max);
			}

			if (j + 3 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i][j + 2] + input_array_b[i][j + 3];
				result_max = get_max(temp, result_max);
			}

			//green
			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_b[i][j] + input_array_b[i + 1][j] + input_array_b[i + 1][j + 1] + input_array_b[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i - 1][j + 1] + input_array_b[i - 1][j + 2];
				result_max = get_max(temp, result_max);
			}

			//yellow
			if (i + 1 <= y && j + 1 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i + 1][j] + input_array_b[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			//orange
			if (i + 1 <= y && j + 2 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i][j + 2] + input_array_b[i + 1][j];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i + 1][j + 1] + input_array_b[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_b[i][j] + input_array_b[i + 1][j] + input_array_b[i + 2][j] + input_array_b[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i][j + 2] + input_array_b[i - 1][j + 2];
				result_max = get_max(temp, result_max);
			}

			//pink

			if (i + 2 <= y && j - 1 >= 1 && j - 1 <= x) {
				temp = input_array_b[i][j] + input_array_b[i + 1][j] + input_array_b[i + 2][j] + input_array_b[i + 1][j - 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i][j + 2] + input_array_b[i - 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_b[i][j] + input_array_b[i + 1][j] + input_array_b[i + 2][j] + input_array_b[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 1 <= y && j + 2 <= x) {
				temp = input_array_b[i][j] + input_array_b[i][j + 1] + input_array_b[i][j + 2] + input_array_b[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}
		}
	}

	//좌우
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			//blue
			if (i + 3 <= y) {
				temp = input_array_c[i][j] + input_array_c[i + 1][j] + input_array_c[i + 2][j] + input_array_c[i + 3][j];
				result_max = get_max(temp, result_max);
			}

			if (j + 3 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i][j + 2] + input_array_c[i][j + 3];
				result_max = get_max(temp, result_max);
			}

			//green
			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_c[i][j] + input_array_c[i + 1][j] + input_array_c[i + 1][j + 1] + input_array_c[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i - 1][j + 1] + input_array_c[i - 1][j + 2];
				result_max = get_max(temp, result_max);
			}

			//yellow
			if (i + 1 <= y && j + 1 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i + 1][j] + input_array_c[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			//orange
			if (i + 1 <= y && j + 2 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i][j + 2] + input_array_c[i + 1][j];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i + 1][j + 1] + input_array_c[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_c[i][j] + input_array_c[i + 1][j] + input_array_c[i + 2][j] + input_array_c[i + 2][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i][j + 2] + input_array_c[i - 1][j + 2];
				result_max = get_max(temp, result_max);
			}

			//pink

			if (i + 2 <= y && j - 1 >= 1 && j - 1 <= x) {
				temp = input_array_c[i][j] + input_array_c[i + 1][j] + input_array_c[i + 2][j] + input_array_c[i + 1][j - 1];
				result_max = get_max(temp, result_max);
			}

			if (i - 1 <= y && i - 1 >= 1 && j + 2 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i][j + 2] + input_array_c[i - 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 2 <= y && j + 1 <= x) {
				temp = input_array_c[i][j] + input_array_c[i + 1][j] + input_array_c[i + 2][j] + input_array_c[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}

			if (i + 1 <= y && j + 2 <= x) {
				temp = input_array_c[i][j] + input_array_c[i][j + 1] + input_array_c[i][j + 2] + input_array_c[i + 1][j + 1];
				result_max = get_max(temp, result_max);
			}
		}
	}
	
	cout << result_max;

	return 0;
}