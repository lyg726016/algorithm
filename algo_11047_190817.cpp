#include <iostream>

using namespace std;

int input_n;
int input_target;
int arr_coin[11];
int result = 0;

int main(){

	cin >> input_n >> input_target;

	for (int i = 0; i < input_n; i++){
		cin >> arr_coin[i];
	}

	while (input_target != 0){
		for (int i = input_n -1; i >= 0; i--){
			if (input_target == arr_coin[i]){
				input_target -= arr_coin[i];
				break;
			}
			else if (input_target < arr_coin[i]){
				input_target -= arr_coin[i - 1];
				break;
			}
		}
		result++;
	}
	cout << result;
	return 0;
}