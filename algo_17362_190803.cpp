#include <iostream>

using namespace std;

long long input_a;

int main(){

	cin >> input_a;
	input_a = input_a % 24;

	if (input_a == 1 || input_a == 9 || input_a == 17){
		cout << "1";
	}
	else if (input_a == 0 || input_a == 2 || input_a == 8 || input_a == 10 || input_a == 16 || input_a == 18){
		cout << "2";
	}
	else if (input_a == 3 || input_a == 7 || input_a == 11 || input_a == 15 || input_a == 19 || input_a == 23){
		cout << "3";
	}
	else if (input_a == 4 || input_a == 6 || input_a == 12 || input_a == 14 || input_a == 20 || input_a == 22){
		cout << "4";
	}
	else if (input_a == 5 || input_a == 13 || input_a == 21){
		cout << "5";
	}

	return 0;
}