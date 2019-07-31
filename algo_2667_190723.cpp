#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input_a;
char map[25][25 + 1];
int is_visit[25][25] = { 0, };
vector <int> count_d;
int temp_result = 0;


char input_c;



//단지 내의 집 수 출력
void dfs(int i, int j) {
	//up
	if (i > 0) {
		if (map[i - 1][j] == '1' && is_visit[i - 1][j] == 0) {
			is_visit[i - 1][j] = 1;
			temp_result++;
			dfs(i - 1, j);
		}
	}
	//down
	if (i < input_a - 1) {
		if (map[i + 1][j] == '1' && is_visit[i + 1][j] == 0) {
			is_visit[i + 1][j] = 1;
			temp_result++;
			dfs(i + 1, j);
		}
	}
	//left
	if (j > 0) {
		if (map[i][j - 1] == '1' && is_visit[i][j - 1] == 0) {
			is_visit[i][j - 1] = 1;
			temp_result++;
			dfs(i, j - 1);
		}
	}
	//right
	if (j < input_a - 1) {
		if (map[i][j + 1] == '1' && is_visit[i][j + 1] == 0) {
			is_visit[i][j + 1] = 1;
			temp_result++;
			dfs(i, j + 1);
		}
	}
}

int main() {

	cin >> input_a;

	for (int i = 0; i < input_a; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < input_a; i++) {
		for (int j = 0; j < input_a; j++) {
			if (map[i][j] == '1') {
				if (is_visit[i][j] == 0) {
					temp_result = 1;
					is_visit[i][j] = 1;
					dfs(i, j);
					count_d.push_back(temp_result);
					temp_result = 0;
				}
			}
		}
	}

	cout << count_d.size() << endl;

	sort(count_d.begin(), count_d.end());
	for (int i = 0; i < count_d.size(); i++)
		cout << count_d[i] << endl;

	return 0;
}