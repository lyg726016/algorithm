//�׽�Ʈ���̽��� ����, �ڿ����� ���� Ȯ���� �ľ�.
//�ð� �ʰ�

#include <iostream>

using namespace std;

//https://www.acmicpc.net/problem/1003

//0, 1�� ����
int count_zero = 0;
int count_one = 0;
//�׽�Ʈ ���̽� ����
int t = 0;
//input ���� �迭
int *input_number;

#define MAX_N 41

int* array_fibonacci_zero;
int* array_fibonacci_one;

void printf_fibo(int n) {
	cout << array_fibonacci_zero[n] << " " << array_fibonacci_one[n] << endl;
}

//n -> 1�ǰ��� / 0�� ����
//0 -> 0 / 1
//1 -> 1 / 0
//2 -> 1 / 1
//3 -> 2 / 1
//4 -> 3 / 2
//5 -> 5 / 3
void fibonacci() {
	//i -> 2 ~ 40
	for (int i = 2; i < MAX_N; i++) {
		array_fibonacci_zero[i] = array_fibonacci_zero[i - 1] + array_fibonacci_zero[i - 2];
		array_fibonacci_one[i] = array_fibonacci_one[i - 1] + array_fibonacci_one[i - 2];
	}
}


int main() {
	array_fibonacci_zero = new int[MAX_N];
	array_fibonacci_one = new int[MAX_N];
	array_fibonacci_zero[0] = 1;
	array_fibonacci_one[0] = 0;
	array_fibonacci_zero[1] = 0;
	array_fibonacci_one[1] = 1;
	cin >> t;

	input_number = new int[t + 1];

	
	for (int i = 0; i < t; i++) {
		cin >> input_number[i];
	}

	fibonacci();

	for (int i = 0; i < t; i++) {
		printf_fibo(input_number[i]);
	}

	return 0;
}