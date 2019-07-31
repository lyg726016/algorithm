#include <iostream>

using namespace std;
int input_a, input_b;
int * array_input_a, *array_input_b;
int tc;
int * result;

int main() {
	cin >> tc;
	result = new int[tc];
	array_input_a = new int[tc];
	array_input_b = new int[tc];

	for (int i = 0; i < tc; i++) {

		cin >> input_a >> input_b;
		result[i] = input_a + input_b;
		array_input_a[i] = input_a;
		array_input_b[i] = input_b;

	}

	for (int i = 0; i < tc; i++)
		cout << "Case #" << i + 1 << ": " << array_input_a[i] << " + " << array_input_b[i] << " = " << result[i] << endl;

	return 0;
}