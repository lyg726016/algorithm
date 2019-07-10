#include <iostream>

//https://www.acmicpc.net/problem/12969

using namespace std;

#define MAX_N 30;

//문자열의 길이
int n = 0;
// 0 ≤ i < j < N 이면서 S[i] < S[j]를 만족하는 (i, j) 쌍의 개수
// i = 0 ~ N -2 (n-1개) / j = 1 ~ N -1(n-1개)
int k = 0;
int max_k = 0;
char * output_char_array;

//k가 가능한지 (최대를 초과하는지, 가능한 경우인지)
bool is_possible = false;

int count_a = 0;
int count_b = 0;
int count_c = 0;
int max = 0;

//k를 만족하는 a,b,c의 개수를 찾았을 경우
bool is_found = false;
int temp_a = 0;
int temp_b = 0;
int temp_c = 0;

//조건을 만족하는 S의 최대 개수
//1의 개수 * 2의 개수 + 2의 개수 * 3의 개수
//1의 개수 * (2의 개수 + 3의 개수) + 2의 개수 * 3 의 개수
//최대 조건을 만족하는지
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
					//k를 만족하는 a,b,c의 개수를 찾았을 경우
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


//k에 적합한 문자열 생성
void make_string(int input_n, int input_k) {
	//0~input_n -1까지 => input_n개
}

int main() {

	output_char_array = new char[30];
	
	cin >> n >> k;

	is_exist(n, k);

	if (is_possible) {
		//k를 만족하는 a,b,c의 개수를 찾았을 경우
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
		}//k를 만족하는 a,b,c의 개수를 못 찾았을 경우
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
			//k가 문자열의 크기보다 클 경우 -> 계산식 필요.
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