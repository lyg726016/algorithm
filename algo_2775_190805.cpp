#include <iostream>

using namespace std;

int tc;
int input_k, input_n;
int temp_sum = 0;
int count_person[15][15];

int main() {

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> input_k >> input_n;


		for (int i = 1; i <= 14; i++) {
			count_person[0][i] = i;
		}

		for (int i = 1; i <= 14; i++) {
			for (int j = 1; j <= 14; j++) {
				for (int k = 1; k <= j; k++) {
					temp_sum += count_person[i - 1][k];

				}
				count_person[i][j] = temp_sum;
				temp_sum = 0;
			}
		}

		cout << count_person[input_k][input_n] << '\n';

	}

	return 0;
}