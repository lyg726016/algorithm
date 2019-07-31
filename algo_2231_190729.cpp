#include <iostream>

using namespace std;

//2의 0승 ~ 2의 20승
int input_number;

//각 자리수의 합을 더하는 함수
int get_each_sum(int input_num) {
	int result = 0;
	
	//5555142

	//백만
	int qoraks = input_num / 1000000;
	input_num -= qoraks * 1000000;

	//십만
	int tlqaks = input_num / 100000;
	input_num -= tlqaks * 100000;

	//만
	int aks = input_num / 10000;
	input_num -= aks * 10000;

	//천
	int cjs = input_num / 1000;
	input_num -= cjs * 1000;

	//백
	int qor = input_num / 100;
	input_num -= qor * 100;

	//십
	int tlq = input_num / 10;
	input_num -= tlq * 10;

	//일
	int dlf = input_num ;
	input_num -= tlq;

	result = qoraks + tlqaks + aks + cjs + qor + tlq + dlf;

	return result;
}

//입력값 + 각자리수의 합을 출력하는 함수


int main() {

	cin >> input_number;
	for (int i = 0; i <= 1000000; i++) {
		if ((get_each_sum(i) + i) == input_number) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}