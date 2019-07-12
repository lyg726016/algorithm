#include <iostream>

using namespace std;

int n = 0;
int m = 0;

//5�� ����
int get_five(int input) {
	int result = 0;
	for (int i = 0; i < 17; i++) {
		result += input / 5;
		input = input / 5;
	}

	return result;
}

//2�� ����
int get_two(int input) {
	int result = 0;
	for (int i = 0; i < 32; i++) {
		result += input / 2;
		input = input / 2;
	}

	return result;
}

int main() {

	cin >> n >> m;

	//nCm -> n!���� 5�� ����
	int a = get_five(n);

	int b = get_five(m);
	int c = get_five(n - m);

	//nCm -> n!���� 2�� ����
	int d = get_two(n);
	int e = get_two(m);
	int f = get_two(n - m);

	int g = a - b - c;
	int h = d - e - f;


	//5�� 2�� �� = 0�� ����
	if (g <= 0 || h <= 0)
		cout << 0;

	else {
		if (g >= h) {
			cout << h;
		}
		else {
			cout << g;
		}
	}

	return 0;
}