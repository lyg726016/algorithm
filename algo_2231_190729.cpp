#include <iostream>

using namespace std;

//2�� 0�� ~ 2�� 20��
int input_number;

//�� �ڸ����� ���� ���ϴ� �Լ�
int get_each_sum(int input_num) {
	int result = 0;
	
	//5555142

	//�鸸
	int qoraks = input_num / 1000000;
	input_num -= qoraks * 1000000;

	//�ʸ�
	int tlqaks = input_num / 100000;
	input_num -= tlqaks * 100000;

	//��
	int aks = input_num / 10000;
	input_num -= aks * 10000;

	//õ
	int cjs = input_num / 1000;
	input_num -= cjs * 1000;

	//��
	int qor = input_num / 100;
	input_num -= qor * 100;

	//��
	int tlq = input_num / 10;
	input_num -= tlq * 10;

	//��
	int dlf = input_num ;
	input_num -= tlq;

	result = qoraks + tlqaks + aks + cjs + qor + tlq + dlf;

	return result;
}

//�Է°� + ���ڸ����� ���� ����ϴ� �Լ�


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