#include <iostream>

int arr_input[9];
int max_v = 0;
int max_i = 10;

using namespace std;

int main(){
	for (int i = 0; i < 10; i++){
		cin >> arr_input[i];
		if (arr_input[i] > max_v) {
			max_v = arr_input[i];
			max_i = i;
		}
	}

	cout << max_v << '\n' << max_i + 1;

	return 0;
}