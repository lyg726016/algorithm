#include <iostream>

using namespace std;

int input_n;
int input_x[50 + 1];
int input_y[50 + 1];

int score = 0;

int main() {

	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		cin >> input_x[i];
		cin >> input_y[i];
	}

	for (int i = 0; i < input_n; i++) {
		score = 0;
		for (int j = 0; j < input_n; j++) {
			if (input_x[i] < input_x[j]) {
				if (input_y[i] < input_y[j]) {
					score++;
				}
			}
		}
		cout << score  + 1<< '\n';
	}
	return 0;
}