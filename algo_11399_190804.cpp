#include <iostream>
#include <algorithm>

using namespace std;

int input_c;
int arr_input[1000];
int sum = 0;
int result = 0;

int main(){
	/*5
		3 1 4 3 2*/

		//32

	cin >> input_c;

	for (int i = 0; i < input_c; i++){
		cin >> arr_input[i];
	}

	sort(arr_input, arr_input + input_c);
	
	for (int i = 0; i < input_c; i++){
		sum += arr_input[i];
		result += sum;
	}


	cout << result;

	return 0;
}