#include <iostream>

using namespace std;

int not_self_number[10001] = { 1, 0, };


int dlf;
int tlq;
int qor;
int cjs;
int aks;

//1 10 100 1000 10000
int get_self_number(int input){
	int temp_input = input;
	aks = input / 10000;
	input -= aks * 10000;

	cjs = input  / 1000;
	input -= cjs * 1000;

	qor = input / 100;
	input -= qor * 100;

	tlq = input / 10;
	input -= tlq * 10;

	dlf = input;

	return temp_input + aks + cjs + qor + tlq + dlf;
}

int main(){


	for (int i = 1; i < 10001; i++){
		not_self_number[get_self_number(i)] = 1;
	}

	for (int i = 1; i < 10001; i++){
		if (not_self_number[i] == 0) cout << i << '\n';
	}

	return 0;
}