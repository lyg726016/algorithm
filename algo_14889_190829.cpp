#include <iostream>
#include <queue>

using namespace std;

int input_n;
int arr_input[21][21];
int is_team[20] = { 0, };
int result = 99999990999;

void solve(int count, int idx) {
	if (idx == input_n) {
		return;
	}
	if (count == input_n / 2) {
		int sum_team_a = 0;
		int sum_team_b = 0;

		for (int i = 0; i < input_n; i++) {
			for (int j = 0; j < input_n; j++) {
				if (is_team[i] && is_team[j]) sum_team_a += arr_input[i][j];
				if (!is_team[i] && !is_team[j]) sum_team_b += arr_input[i][j];
			}
		}
		result = min(result, abs(sum_team_a - sum_team_b));
		return;
	}

	//ÆÀ¿¡ Æ÷ÇÔ
	is_team[idx] = 1;
	solve(count + 1, idx + 1);
	//ÆÀ¿¡¼­ Á¦¿Ü
	is_team[idx] = 0;
	solve(count, idx + 1);
}



int main() {

	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			cin >> arr_input[i][j];
		}
	}
	solve(0, 0);
	cout << result;

	return 0;
}