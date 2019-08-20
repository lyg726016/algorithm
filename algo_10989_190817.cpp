#include <iostream>

using namespace std;

int arr_input[10001] = { 0, };
int input_n;
int temp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input_n;

	for (int i = 0; i < input_n; i++){
		cin >> temp;
		arr_input[temp]++;
	}

	for (int i = 0; i < 10001; i++){
		while(arr_input[i] != 0){
			cout << i << '\n';
			arr_input[i]--;
		}
	}
	scanf_s("%d", &temp);

	return 0;
}