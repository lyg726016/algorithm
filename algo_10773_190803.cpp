#include <iostream>

using namespace std;

int count_number = 0;
int arr_input[100001];
int temp_input;
int current_index = 0;
long long total_sum = 0;

int main(){
	cin >> count_number;

	for (int i = 0; i < count_number; i++){
		cin >> temp_input;
		if (temp_input == 0){
			current_index--;
		}
		else{
			arr_input[current_index] = temp_input;
			current_index++;
		}
	}

	for (int i = 0; i < current_index; i++){
		total_sum += arr_input[i];
	}
	
	cout << total_sum;

	return 0;
}