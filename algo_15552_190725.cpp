#include <iostream>

using namespace std;

int input_a, input_b;
int tc;
int * result;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> tc;
	result = new int[tc];

	for (int i = 0; i < tc; i++) {
		cin >> input_a >> input_b;
		result[i] = input_a + input_b;
	}

	for (int i = 0; i < tc; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}