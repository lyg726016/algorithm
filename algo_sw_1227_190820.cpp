//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD&categoryId=AV14wL9KAGkCFAYD&categoryType=CODE

#include <iostream>
#include <queue>

using namespace std;

int tc_number;
int input_n;

int main() {

	for (int i = 1; i < 11; i++) {
		scanf_s("%1d", &tc_number);
		int map[101][101] = { 5, };
		queue <pair <int, int>> q;

		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				scanf_s("%1d", &input_n);
				map[j][k] = input_n;
				if (input_n == 2) {
					q.push(make_pair(j, k));
				}
			}
		}

		pair <int, int> t_p;
		bool is_possble = false;

		while (q.size() != 0) {
			t_p = q.front();
			q.pop();

			if (t_p.first > 0) {
				if (map[t_p.first - 1][t_p.second] == 3) {
					is_possble = true;
					break;
				}

				if (map[t_p.first - 1][t_p.second] == 0) {
					q.push(make_pair(t_p.first - 1, t_p.second));
					map[t_p.first - 1][t_p.second] = 5;
				}
				
			}

			if (t_p.first < 99) {
				if (map[t_p.first + 1][t_p.second] == 3) {
					is_possble = true;
					break;
				}
				if (map[t_p.first + 1][t_p.second] == 0) {
					q.push(make_pair(t_p.first + 1, t_p.second));
					map[t_p.first + 1][t_p.second] = 5;
				}
			}

			if (t_p.second > 0) {
				if (map[t_p.first][t_p.second - 1] == 3) {
					is_possble = true;
					break;
				}
				if (map[t_p.first][t_p.second - 1] == 0) {
					q.push(make_pair(t_p.first, t_p.second - 1));
					map[t_p.first][t_p.second - 1] = 5;
				}
			}

			if (t_p.second < 99) {
				if (map[t_p.first][t_p.second + 1] == 3) {
					is_possble = true;
					break;
				}
				if (map[t_p.first][t_p.second + 1] == 0) {
					q.push(make_pair(t_p.first, t_p.second + 1));
					map[t_p.first][t_p.second + 1] = 5;
				}
			}
		}


		if (is_possble) {
			cout << "#" << i << " 1" << '\n';
		}
		else {
			cout << "#" << i << " 0" << '\n';
		}
	}


	return 0;
}