#include <iostream>
#include <string.h>

using namespace std;

#define MAX_LENGTH 50

int count_a = 0;
int count_b = 0;
int count_c = 0;

//a
//b = b + 1
//c  = c + 2 

int main() {

	char input_str[MAX_LENGTH + 1];
	char output_str[MAX_LENGTH + 1];

	cin >> input_str;

	char MAX_A = 0;
	char MAX_B = 0;
	char MAX_C = 0;

	int sz = strlen(input_str);

	for (int i = 0; i < sz; i++) {
		if (input_str[i] == 'A') MAX_A++;
		if (input_str[i] == 'B') MAX_B++;
		if (input_str[i] == 'C') MAX_C++;
		output_str[i] = 'A';
	}

	int c_number = MAX_C * 3 - 2;
	int b_number = MAX_B * 2 - 1;

	if (sz < c_number) {
		cout << "-1";
		return 0;
	}
	if (sz < b_number) {
		cout << "-1";
		return 0;
	}

	if (sz == b_number && sz == c_number) {
		cout << "-1";
		return 0;
	}

	for (int i = 0; i < sz; i++) {
		//c가 우선
		if (c_number >= b_number) {
			//초기시작일 때
			if (i == 0) {
				if (c_number >= 1) {
					output_str[i] = 'C';
					c_number -= 3;
					MAX_C--;
				}
			}
			//초기 시작 아닐 때
			else {
				//i가 2보다 클 때 = 비교 가능
				if (i > 2) {
					//C가 들어갈 수 있으면 C삽입
					if (c_number >= 1)
						if (output_str[i - 1] != 'C' && output_str[i - 2] != 'C') {
							output_str[i] = 'C';
							c_number -= 3;
							MAX_C--;
						}
					//C가 들어갈 수 없으면 B확인
						else {
							if (b_number >= 1)
								if (output_str[i - 1] != 'B') {
									output_str[i] = 'B';
									b_number -= 2;
									MAX_B--;
								}
						}
				}
				//1,2 일 때
				else {
					//1일 때
					if (i == 1) {
						if (c_number >= 1)
							//C넣을 수 있으면 넣어
							if (output_str[i - 1] != 'C') {
								output_str[i] = 'C';
								c_number -= 3;
								MAX_C--;
							}
						//C 못넣으면
							else {
								if (b_number >= 1)
									//B넣어
									if (output_str[i - 1] != 'B') {
										output_str[i] = 'B';
										b_number -= 2;
										MAX_B--;
									}
							}
					}
					//2일 때
					else {
						if (c_number >= 1)
							//C넣을 수 있으면 넣어
							if (output_str[i - 1] != 'C' && output_str[i - 2] != 'C') {
								output_str[i] = 'C';
								c_number -= 3;
								MAX_C--;
							}
						//C 못넣으면
							else {
								if (b_number >= 1)
									//B넣어
									if (output_str[i - 1] != 'B') {
										output_str[i] = 'B';
										b_number -= 2;
										MAX_B--;
									}
							}
					}
				}
			}
		}
		//b가 우선
		else {
			//초기시작일 때
			if (i == 0) {
				if (b_number >= 1) {
					output_str[i] = 'B';
					b_number -= 2;
					MAX_B--;
				}
			}
			//초기 시작 아닐 때
			else {
				//i가 1보다 클 때 = 비교 가능
				if (i > 1) {
					if (b_number >= 1)
						//B 넣을 수 있으면 넣어
						if (output_str[i - 1] != 'B') {
							output_str[i] = 'B';
							b_number -= 2;
							MAX_B--;
						}
					//B 못넣을 때
						else {
							if (c_number >= 1)
								//C 넣을 수 있으면 넣어
								if (output_str[i - 1] != 'C' && output_str[i - 2] != 'C') {
									output_str[i] = 'C';
									c_number -= 3;
									MAX_C--;
								}
						}
				}
				//1 일 때
				else {
					if (b_number >= 1)
						//B넣을 수 있으면 넣어
						if (output_str[i - 1] != 'B') {
							output_str[i] = 'B';
							b_number -= 2;
							MAX_B--;
						}
					//B를 못 넣을 때
						else {
							if (c_number >= 1)
								//C를 넣을 수 있으면 넣어
								if (output_str[i - 1] != 'C') {
									output_str[i] = 'C';
									c_number -= 3;
									MAX_C--;
								}
						}
				}
			}
		}
	}

	if (MAX_C > 0) {
		cout << "-1";
		return 0;
	}
	if (MAX_B > 0) {
		cout << "-1";
		return 0;
	}
	output_str[sz] = '\0';
	cout << output_str;

	return 0;
}