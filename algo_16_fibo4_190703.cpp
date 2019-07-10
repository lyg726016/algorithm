#include <iostream>
//https://www.acmicpc.net/problem/10826
using namespace std;

#define MAX_LENGTH 5001
#define MAX_INPUT 10001

int input;
// array_fibo[i] ... i번째 피보 값
//1000자리 이하로 가정
//자료형 -> [i] 뒤 각각 0의자리 1의자리 담음
int array_fibo[MAX_INPUT][MAX_LENGTH];

void get_fibo(int input_n) {

	//모두 0으로 초기화
	for (int i = 0; i <= input_n; i++) {
		for (int j = 0; j < MAX_LENGTH; j++) {
			array_fibo[i][j] = 0;
		}
	}

	//fibo[1] = 1
	array_fibo[1][1] = 1;

	for (int i = 2; i <= input_n; i++) {
		for (int j = 1; j < MAX_LENGTH - 1; j++) {
			if (array_fibo[i][j] + array_fibo[i - 1][j] + array_fibo[i - 2][j] >= 10) {
				array_fibo[i][j] = array_fibo[i][j] + array_fibo[i - 1][j] + array_fibo[i - 2][j] - 10;
				array_fibo[i][j + 1] = array_fibo[i][j + 1] + 1;
			}
			else {
				array_fibo[i][j] = array_fibo[i][j] + array_fibo[i - 1][j] + array_fibo[i - 2][j];
			}
		}
	}
}

int main() {
	cin >> input;
	get_fibo(input);

	//출력 = array_fibo[input][1~1000]까지 1000부터 시작해서 0이 아닐때부터 출력 시작
	int start_number = 0;

	for (int i = MAX_LENGTH - 1; i >= 1; i--) {
		if (array_fibo[input][i] != 0) {
			start_number = i;
			break;
		}
	}

	if (input == 0) {
		cout << 0;
		return 0;
	}


	for (int i = start_number; i >= 1; i--) {
		//printf("%d", array_fibo[input][i]);
		cout << array_fibo[input][i];
	}

	return 0;
}