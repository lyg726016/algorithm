#include <iostream>

using namespace std;

int input_n;
long long result = 1;

void solve(int input_n){
	if (input_n == 0){
		cout << result;
		return;
	}
	result *= input_n;
	solve(input_n - 1);
}

int main(){
	cin >> input_n;
	solve(input_n);

	return 0;
}