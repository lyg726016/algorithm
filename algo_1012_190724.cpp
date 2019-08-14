#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 50

int T;
int M, N, K;

int map[MAX][MAX] = { 0, };

int input_x, input_y;
int * result;
int temp = 0;

queue <pair<int, int>> q;
pair <int, int> temp_pair;

void dfs(int t) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));

				while (!q.empty()) {
					temp_pair = q.front();
					q.pop();

					if (temp_pair.first > 0)
						if (map[temp_pair.first - 1][temp_pair.second] == 1) {
							q.push(make_pair(temp_pair.first - 1, temp_pair.second));
							map[temp_pair.first - 1][temp_pair.second] = 0;
						}

					if (temp_pair.second > 0)
						if (map[temp_pair.first][temp_pair.second - 1] == 1) {
							q.push(make_pair(temp_pair.first, temp_pair.second - 1));
							map[temp_pair.first][temp_pair.second - 1] = 0;
						}

					if (temp_pair.first < N - 1)
						if (map[temp_pair.first + 1][temp_pair.second] == 1) {
							q.push(make_pair(temp_pair.first + 1, temp_pair.second));
							map[temp_pair.first + 1][temp_pair.second] = 0;
						}

					if (temp_pair.second < M - 1)
						if (map[temp_pair.first][temp_pair.second + 1] == 1) {
							q.push(make_pair(temp_pair.first, temp_pair.second + 1));
							map[temp_pair.first][temp_pair.second + 1] = 0;
						}
				}
				temp++;
			}
		}
	}

	result[t] = temp;
	temp = 0;
}

int main() {
	cin >> T;
	result = new int[T];

	for (int t = 0; t < T; t++) {

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> input_x >> input_y;
			map[input_y][input_x] = 1;
		}

		dfs(t);
		memset(map, 0, sizeof(map));
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	return 0;
}