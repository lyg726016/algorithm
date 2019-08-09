#include <iostream>

using namespace std;

int input_n;
long long result = 0;

long long value_[10][100 + 1] = { 0, };

int main() {
	cin >> input_n;

	value_[0][1] = 0;
	value_[1][1] = 1;
	value_[2][1] = 1;
	value_[3][1] = 1;
	value_[4][1] = 1;
	value_[5][1] = 1;
	value_[6][1] = 1;
	value_[7][1] = 1;
	value_[8][1] = 1;
	value_[9][1] = 1;


	for (int i = 0; i < 10; i++) {
		for (int j = 2; j <= input_n; j++) {
			if (i == 0) {
				value_[i][j] = value_[i + 1][j - 1] % 1000000000;
			}
			else if (i == 9) {
				value_[i][j] = value_[i - 1][j - 1] % 1000000000;
			}
			else {
				value_[i][j] = (value_[i - 1][j - 1] + value_[i + 1][j - 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		result = (result + value_[i][input_n]) % 1000000000;
	}

	cout << result % 1000000000;

	return 0;
}