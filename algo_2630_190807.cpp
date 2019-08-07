#include <iostream>

using namespace std;

int color[15][15];

int input_n;

int result_white = 0;
int result_blue = 0;

void solve(int start_i, int end_i, int start_j, int end_j) {
	int divided_i = (start_i + end_i) / 2;
	int divided_j = (start_j + end_j) / 2;
	int is_all_same = true;

	//ÁÂ»ó
	int current_color = color[start_i][start_j];
	for (int i = start_i; i < divided_i; i++) {
		for (int j = start_j; j < divided_j; j++) {
			if (color[i][j] != current_color) {
				is_all_same = false;
				break;
			}
		}
	}
	if (!is_all_same) {
		solve(start_i, divided_i, start_j, divided_j);
	}
	else {
		if (current_color)result_blue++;
		else result_white++;
	}

	is_all_same = true;
	//ÁÂÇÏ
	current_color = color[divided_i][start_j];
	for (int i = divided_i; i < end_i; i++) {
		for (int j = start_j; j < divided_j; j++) {
			if (color[i][j] != current_color) {
				is_all_same = false;
				break;
			}
		}
	}
	if (!is_all_same) {
		solve(divided_i, end_i, start_j, divided_j);
	}
	else {
		if (current_color)result_blue++;
		else result_white++;
	}

	is_all_same = true;
	//¿ì»ó
	current_color = color[start_i][divided_j];
	for (int i = start_i; i < divided_i; i++) {
		for (int j = divided_j; j < end_j; j++) {
			if (color[i][j] != current_color) {
				is_all_same = false;
				break;
			}
		}
	}
	if (!is_all_same) {
		solve(start_i, divided_i, divided_j, end_j);
	}
	else {
		if (current_color)result_blue++;
		else result_white++;
	}

	is_all_same = true;
	//¿ìÇÏ
	current_color = color[divided_i][divided_j];
	for (int i = divided_i; i < end_i; i++) {
		for (int j = divided_j; j < end_j; j++) {
			if (color[i][j] != current_color) {
				is_all_same = false;
				break;
			}
		}
	}
	if (!is_all_same) {
		solve(divided_i, end_i, divided_j, end_j);
	}
	else {
		if (current_color)result_blue++;
		else result_white++;
	}
}

int main() {
	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			cin >> color[i][j];
		}
	}

	solve(0, input_n, 0, input_n);

	cout << result_white << '\n' << result_blue;

	return 0;
}