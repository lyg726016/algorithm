#include <iostream>

using namespace std;

int input_a;
int cjs;
int qor;
int tlq;
int dlf;

int result = 0;

int is_hansu(int input){
	int temp = input;

	cjs = input / 1000;
	input -= cjs * 1000;
	qor = input / 100;
	input -= qor * 100;
	tlq = input / 10;
	input -= tlq * 10;
	dlf = input;

	input = temp;

	if (input < 100)
		return 1;
	else{
		if (input < 1000){
			if (qor - tlq == tlq - dlf)
				return 1;
			else
				return 0;
		}
		else{
			return 0;
		}
	}
}

int main(){

	cin >> input_a;
	for (int i = 1; i <= input_a; i++){
		result += is_hansu(i);
	}

	cout << result;
	return 0;
}