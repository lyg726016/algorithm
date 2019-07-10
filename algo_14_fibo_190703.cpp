#include <iostream>
//https://www.acmicpc.net/problem/2748
using namespace std;

int input;
long long array_fivo[91];

long long get_fivo(int input_n) {
	array_fivo[0] = 0;
	array_fivo[1] = 1;

	for (int i = 2; i <= input_n; i++) {
		array_fivo[i] = array_fivo[i - 1] + array_fivo[i - 2];
	}
	return array_fivo[input_n];
}

int main() {
	cin >> input;
	cout << get_fivo(input);

	return 0;
}