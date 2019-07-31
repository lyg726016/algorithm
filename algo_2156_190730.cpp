#include <iostream>


#define xx [0]
#define xo [1]
#define ox [2]
#define oo [3]

using namespace std;

int count_wine;

int amount_wine[10001];
int temp_max[10001][4] = { 0, };


int get_max(int input_a, int input_b) {
	return input_a > input_b ? input_a : input_b;
}


void get_max() {
	temp_max[0]xx = 0;
	temp_max[0]xo = amount_wine[0];
	temp_max[0]ox = 0;
	temp_max[0]oo = amount_wine[0];

	temp_max[1]xx = 0;
	temp_max[1]xo = amount_wine[1];
	temp_max[1]ox = amount_wine[0];
	temp_max[1]oo = amount_wine[0] + amount_wine[1];

	temp_max[2]xx = get_max(temp_max[1]xx, temp_max[1]ox);
	temp_max[2]xo = get_max(temp_max[1]xx, temp_max[1]ox) + amount_wine[2];
	temp_max[2]ox = get_max(temp_max[1]xo, temp_max[1]oo);
	temp_max[2]oo = amount_wine[1] + amount_wine[2];

	for (int i = 3; i < count_wine; i++) {
		temp_max[i]xx = get_max(temp_max[i - 1]xx, temp_max[i - 1]ox);
		temp_max[i]xo = get_max(temp_max[i - 1]xx, temp_max[i - 1]ox) + amount_wine[i];
		temp_max[i]ox = get_max(temp_max[i - 1]xo, temp_max[i - 1]oo);
		temp_max[i]oo = get_max(temp_max[i - 2]xx + amount_wine[i - 1] + amount_wine[i], temp_max[i - 2]ox + amount_wine[i - 1] + amount_wine[i]);
	}
}


int main() {

	cin >> count_wine;

	for (int i = 0; i < count_wine; i++) {
		cin >> amount_wine[i];
	}

	if (count_wine == 1) {
		cout << amount_wine[0];
	}
	else if (count_wine == 2) {
		cout << amount_wine[0] + amount_wine[1];
	}
	else {
		get_max();
		int result_max = 0;

		for (int i = 0; i < 4; i++) {
			if (result_max < temp_max[count_wine - 1][i]) {
				result_max = temp_max[count_wine - 1][i];
			}
		}
		cout << result_max;
	}

	return 0;
}