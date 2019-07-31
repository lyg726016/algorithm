#include <iostream>

using namespace std;

//1~ 100 000(¹é¸¸)
int input_n;
int result[1000001];

void set_result() {
	result[0] = 0;
	result[1] = 1;
	result[2] = 2;
	result[3] = 3;

	for (int i = 4; i <= 1000000; i++) {
		result[i] = ((result[i - 1] % 15746) + (result[i - 2]) % 15746) % 15746;
	}
}


int main() {

	cin >> input_n;
	set_result();

	cout << result[input_n];

	return 0;
}