#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int input_n;
	cin >> input_n;


	int a[51];
	int b[51];

	for (int i = 0; i < input_n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < input_n; i++) {
		cin >> b[i];
	}

	sort(a, a + input_n);
	sort(b, b + input_n);

	int sum = 0;

	for (int i = 0; i < input_n; i++) {
		sum += a[i] * b[input_n - 1 - i];
	}
	cout << sum;

	return 0;
}