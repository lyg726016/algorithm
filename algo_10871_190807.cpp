#include <iostream>

using namespace std;

int input_n;
int input_x;
int temp;

int main() {
	
	cin >> input_n >> input_x;

	for (int i = 0; i < input_n; i++) {
		cin >> temp;
		if (temp < input_x) {
			cout << temp << " ";
		}
	}

	return 0;
}