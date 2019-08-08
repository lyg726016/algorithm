#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];
int input_x;
int input_y;
int left_tomato = 0;
int day = 0;
queue <pair<int, int>> q;
pair <int, int> current_points;
int q_size;

void search_map() {
	for (int i = 0; i < input_y; i++) {
		for (int j = 0; j < input_x; j++) {
			if (map[i][j] == 0) {
				left_tomato++;
			}
		}
	}
}

void solve() {
	if (!left_tomato) {
		cout << day;
		return;
	}
	q_size = q.size();

	while (q_size) {
		current_points = q.front();
		q.pop();
		q_size--;

		//╩С
		if (current_points.first > 0) {
			if (map[current_points.first - 1][current_points.second] == 0) {
				map[current_points.first - 1][current_points.second] = 1;
				left_tomato--;
				q.push(make_pair(current_points.first - 1, current_points.second));
			}
		}
		//го
		if (current_points.first < input_y - 1) {
			if (map[current_points.first + 1][current_points.second] == 0) {
				map[current_points.first + 1][current_points.second] = 1;
				left_tomato--;
				q.push(make_pair(current_points.first + 1, current_points.second));
			}
		}

		//аб
		if (current_points.second > 0) {
			if (map[current_points.first][current_points.second - 1] == 0) {
				map[current_points.first][current_points.second - 1] = 1;
				left_tomato--;
				q.push(make_pair(current_points.first, current_points.second - 1));
			}
		}

		//©Л
		if (current_points.second < input_x - 1) {
			if (map[current_points.first][current_points.second + 1] == 0) {
				map[current_points.first][current_points.second + 1] = 1;
				left_tomato--;
				q.push(make_pair(current_points.first, current_points.second + 1));
			}
		}
	}
	q_size = q.size();
	if (left_tomato) {
		if (q_size) {
			day++;
			solve();
		}
		else {
			cout << -1;
			return;
		}
	}
	else {
		day++;
		solve();
	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> input_x >> input_y;

	for (int i = 0; i < input_y; i++) {
		for (int j = 0; j < input_x; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	search_map();
	solve();

	return 0;
}