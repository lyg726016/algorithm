#include <iostream>
using namespace std;

int temp_a, temp_b;

int input_count_a[1001] = { 0, };
int input_count_b[1001] = { 0, };

int main() {
	
	for (int i = 0; i < 3; i++) {
		cin >> temp_a;
		input_count_a[temp_a]++;

		cin >> temp_b;
		input_count_b[temp_b]++;
	}

	for (int i = 0; i < 1001; i++) {
		if (input_count_a[i] == 1) {
			cout << i << " ";
			break;
		}
	}

	for (int i = 0; i < 1001; i++) {
		if (input_count_b[i] == 1) {
			cout << i;
			break;
		}
	}
	return 0;
}