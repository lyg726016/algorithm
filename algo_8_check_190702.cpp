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
		//c�� �켱
		if (c_number >= b_number) {
			//�ʱ������ ��
			if (i == 0) {
				if (c_number >= 1) {
					output_str[i] = 'C';
					c_number -= 3;
					MAX_C--;
				}
			}
			//�ʱ� ���� �ƴ� ��
			else {
				//i�� 2���� Ŭ �� = �� ����
				if (i > 2) {
					//C�� �� �� ������ C����
					if (c_number >= 1)
						if (output_str[i - 1] != 'C' && output_str[i - 2] != 'C') {
							output_str[i] = 'C';
							c_number -= 3;
							MAX_C--;
						}
					//C�� �� �� ������ BȮ��
						else {
							if (b_number >= 1)
								if (output_str[i - 1] != 'B') {
									output_str[i] = 'B';
									b_number -= 2;
									MAX_B--;
								}
						}
				}
				//1,2 �� ��
				else {
					//1�� ��
					if (i == 1) {
						if (c_number >= 1)
							//C���� �� ������ �־�
							if (output_str[i - 1] != 'C') {
								output_str[i] = 'C';
								c_number -= 3;
								MAX_C--;
							}
						//C ��������
							else {
								if (b_number >= 1)
									//B�־�
									if (output_str[i - 1] != 'B') {
										output_str[i] = 'B';
										b_number -= 2;
										MAX_B--;
									}
							}
					}
					//2�� ��
					else {
						if (c_number >= 1)
							//C���� �� ������ �־�
							if (output_str[i - 1] != 'C' && output_str[i - 2] != 'C') {
								output_str[i] = 'C';
								c_number -= 3;
								MAX_C--;
							}
						//C ��������
							else {
								if (b_number >= 1)
									//B�־�
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
		//b�� �켱
		else {
			//�ʱ������ ��
			if (i == 0) {
				if (b_number >= 1) {
					output_str[i] = 'B';
					b_number -= 2;
					MAX_B--;
				}
			}
			//�ʱ� ���� �ƴ� ��
			else {
				//i�� 1���� Ŭ �� = �� ����
				if (i > 1) {
					if (b_number >= 1)
						//B ���� �� ������ �־�
						if (output_str[i - 1] != 'B') {
							output_str[i] = 'B';
							b_number -= 2;
							MAX_B--;
						}
					//B ������ ��
						else {
							if (c_number >= 1)
								//C ���� �� ������ �־�
								if (output_str[i - 1] != 'C' && output_str[i - 2] != 'C') {
									output_str[i] = 'C';
									c_number -= 3;
									MAX_C--;
								}
						}
				}
				//1 �� ��
				else {
					if (b_number >= 1)
						//B���� �� ������ �־�
						if (output_str[i - 1] != 'B') {
							output_str[i] = 'B';
							b_number -= 2;
							MAX_B--;
						}
					//B�� �� ���� ��
						else {
							if (c_number >= 1)
								//C�� ���� �� ������ �־�
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