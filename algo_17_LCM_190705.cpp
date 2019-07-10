#include <iostream>
#include <math.h>

using namespace std;

//https://www.acmicpc.net/problem/11688
//유클리드 호제법
//https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95


int main() {
	int input_a;
	int input_b;
	int array_input_a[45001];
	int array_input_b[45001];

	for (int i = 0; i < 45001; i++)
	{
		array_input_a[i] = 0;
		array_input_b[i] = 0;
	}



	int T;
	cin >> T;

	long long *a;
	a = new long long[T];

	for (int j = 0; j < T; j++) {

		cin >> input_a >> input_b;

		int i = 2;

		long long result = 1;

		//input_a
		while (true)
		{
			if (input_a == 1) {
				break;
			}
			if (input_a % i == 0) {
				input_a = input_a / i;
				array_input_a[i]++;
				i = 2;
			}
			else {
				i++;
			}
		}

		i = 2;

		//input_b
		while (true)
		{
			if (input_b == 1) {
				break;
			}
			if (input_b % i == 0) {
				input_b = input_b / i;
				array_input_b[i]++;
				i = 2;
			}
			else {
				i++;
			}
		}

		int max = 1;

		for (int i = 0; i < 45001; i++) {
			//최대 공약수
			/*if (array_input_a[i] != 0 && array_input_b[i] != 0) {
			if (array_input_a[i] >= array_input_b[i]) {
			max *= pow(i, array_input_b[i]);
			}
			else {
			max *= pow(i, array_input_a[i]);
			}
			}*/
			if (array_input_a[i] != 0) {
				if (array_input_a[i] >= array_input_b[i]) {
					result *= pow(i, array_input_a[i]);
				}
				else {
					result *= pow(i, array_input_b[i]);
				}
				array_input_b[i] = 0;
			}

			if (array_input_b[i] != 0) {
				if (array_input_a[i] >= array_input_b[i]) {
					result *= pow(i, array_input_a[i]);
				}
				else {
					result *= pow(i, array_input_b[i]);
				}
			}
		}
		////최대 공약수
		//cout << max << endl;

		//최소 공배수
		a[j] = result;
		result = 1;

		for (int i = 0; i < 45001; i++)
		{
			array_input_a[i] = 0;
			array_input_b[i] = 0;
		}

	}

	for (int i = 0; i < T; i++) {
		cout << a[i] << endl;
	}
	return 0;
}