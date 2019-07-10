#include <iostream>

//https://www.acmicpc.net/problem/12969

using namespace std;

#define MAX_N 30;

//���ڿ��� ����
int n = 0;
// 0 �� i < j < N �̸鼭 S[i] < S[j]�� �����ϴ� (i, j) ���� ����
// i = 0 ~ N -2 (n-1��) / j = 1 ~ N -1(n-1��)
int k = 0;
int max_k = 0;
char * output_char_array;

//k�� �������� (�ִ븦 �ʰ��ϴ���, ������ �������)
bool is_possible = false;

int count_a = 0;
int count_b = 0;
int count_c = 0;
int max = 0;

//k�� �����ϴ� a,b,c�� ������ ã���� ���
bool is_found = false;
int temp_a = 0;
int temp_b = 0;
int temp_c = 0;

//������ �����ϴ� S�� �ִ� ����
//1�� ���� * 2�� ���� + 2�� ���� * 3�� ����
//1�� ���� * (2�� ���� + 3�� ����) + 2�� ���� * 3 �� ����
//�ִ� ������ �����ϴ���
void is_exist(int input_n, int input_k) {
	max = 0;
	
	int current = 0;

	// i 0 ~ n
	// j 0 ~n
	// k 0 ~n
	// i + j + k = n

	for (int i = 0; i <= input_n; i++) {
		for (int j = 0; j <= input_n; j++) {
			for (int k = 0; k <= input_n; k++) {
				if (i + j + k == input_n) {
					current = i*j + j*k + k*i;
					if (current > max) {
						max = current;
						count_a = i;
						count_b = j;
						count_c = k;
					}
					//k�� �����ϴ� a,b,c�� ������ ã���� ���
					if (current == input_k) {
						temp_a = i;
						temp_b = j;
						temp_c = k;
						is_found = true;
					}
					else {

					}
				}
			}
		}
	}

	if (max >= input_k) {
		is_possible = true;
	}
}


//k�� ������ ���ڿ� ����
void make_string(int input_n, int input_k) {
	//0~input_n -1���� => input_n��
}

int main() {

	output_char_array = new char[30];
	
	cin >> n >> k;

	is_exist(n, k);

	if (is_possible) {
		//k�� �����ϴ� a,b,c�� ������ ã���� ���
		if (is_found) {
			for (int i = 0; i < temp_a; i++) {
				printf("A");
			}
			for (int i = 0; i < temp_b; i++) {
				printf("B");
			}
			for (int i = 0; i < temp_c; i++) {
				printf("C");
			}
		}//k�� �����ϴ� a,b,c�� ������ �� ã���� ���
		else {
			if (n > k) {
				for (int i = 0; i < n - k - 1; i++) {
					printf("C");
				}

				for (int i = 0; i < k; i++) {
					printf("A");
				}
				printf("B");
			}
			//k�� ���ڿ��� ũ�⺸�� Ŭ ��� -> ���� �ʿ�.
			else if (n <= k) {
				int divide_num = k / n;
				int nam = k % n;

				if (nam == 0) {

				}
			}
		}
	}
	else {
		printf("-1");
	}

	//cout << output_char_array;

	return 0;
}