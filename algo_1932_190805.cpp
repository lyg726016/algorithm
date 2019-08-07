#include <iostream>
#include <queue>

using namespace std;

int input_n;
int temp;

int input[500 + 1][500 + 1];
int result[500 + 1][500 + 1];

int get_max(int input_a, int input_b) {
	return input_a > input_b ? input_a : input_b;
}

int main() {

	cin >> input_n;

	for (int i = 1; i <= input_n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> temp;
			input[i][j] = temp;
		}
	}


	result[1][1] = input[1][1];

	for (int i = 2; i <= input_n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == j) {
				result[i][j] = result[i - 1][j - 1] + input[i][j];
			}
			else if (j == 1)
			{
				result[i][j] = result[i - 1][j] + input[i][j];
			}
			else{
				result[i][j] = get_max(result[i - 1][j] + input[i][j], result[i - 1][j - 1] + input[i][j]);
			}
			//cout << "result : " << result[i][j] << '\n';
		}
	}

	int max_v = 0;
	for (int i = 1; i <= input_n; i++) {
		if (max_v < result[input_n][i]) {
			max_v = result[input_n][i];
		}
	}

	cout << max_v;

	return 0;
}