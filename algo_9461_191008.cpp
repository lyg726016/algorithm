#include <iostream>

using namespace std;

long long arr_r[101] = { 0, };

void get_result(){
	arr_r[0] = 0;
	arr_r[1] = 1;
	arr_r[2] = 1;
	arr_r[3] = 1;
	for (int i = 4; i <= 100; i++){
		arr_r[i] = arr_r[i - 2] + arr_r[i - 3];
	}
}

int main(){
	int tc;
	cin >> tc;

	get_result();

	for (int i = 0; i < tc; i++){
		int temp;
		cin >> temp;
		cout << arr_r[temp];

		if (i != tc - 1){
			cout << '\n';
		}
	}

	return 0;
}