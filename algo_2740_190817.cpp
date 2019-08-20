#include <iostream>

using namespace std;

int input_a_n;
int input_a_m;

int input_b_n;
int input_b_m;

int a_arr[101][101] = { 0, };
int b_arr[101][101] = { 0, };
int result_arr[101][101] = { 0, };

int sum = 0;

int main(){
	cin >> input_a_n >> input_a_m;
	
	for (int i = 0; i < input_a_n; i++){
		for (int j = 0; j < input_a_m; j++){
			cin >> a_arr[i][j];
		}
	}

	cin >> input_b_n >> input_b_m;

	//input_a_m == input_b_n

	for (int i = 0; i < input_b_n; i++){
		for (int j = 0; j < input_b_m; j++){
			cin >> b_arr[i][j];
		}
	}

	for (int i = 0; i < input_a_n; i++){
		for (int j = 0; j < input_b_m; j++){
			for (int k = 0; k < input_b_n; k++){
				result_arr[i][j] += a_arr[i][k] * b_arr[k][j];
			}
		}
	}

	for (int i = 0; i < input_a_n; i++){
		for (int j = 0; j < input_b_m; j++){
			cout << result_arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}