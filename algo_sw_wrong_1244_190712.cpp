#include <iostream>
#include <string.h>

using namespace std;

int T;
//input -> int�� ��ȯ�ϱ� ��
char string_input[6] = "";

//����� ������
int int_input[6];
//��ȭ Ƚ��
int change_count = 0;
//�ְ� ��� ����
bool is_sorted = false;
//������� ������ ��ġ
int index_ = 0;
//���� ���� �迭���� �ִ� ��
int temp_max = 0;

//���
char result[10][20];
string temp_result[10];

int main() {
	cin >> T;


	for (int i = 0; i < T; i++) {
		bool temp_is_sorted = true;
		//���Ŀ���
		is_sorted = false;
		//������� ���� ��ġ
		index_ = 0;

		cin >> string_input;

		//��ȯ

		int size = strlen(string_input);
		//����
		//�־��� ������ �Ѱ��� ����
		if (size == 1) {
			temp_result[i] = string_input[0];
			break;
		}

		//��ȯ �� char -> integer
		for (int i = 0; i < size; i++) {
			char change = string_input[i];
			char * pointer_change = &change;
			//��ȯ �Ϸ�.
			int_input[i] = atoi(pointer_change);
		}
		//Ƚ���� ���� ���� ���� ����
		cin >> change_count;

		while (true) {
			//Ƚ�� ��� ����
			if (change_count == 0) {
				break;
			}

			//������ ũ�Ⱑ ���� �κ��� �ϳ��� ���� �� ���� �ȵ�.
			for (int i = 1; i < size; i++) {
				if (int_input[i] < int_input[i - 1]) {
					temp_is_sorted = false;
				}
			}

			if (temp_is_sorted) {
				is_sorted = true;
			}
			else {
				is_sorted = false;
			}

			
			//���� ���� ���� Ȯ��(�ϳ��ϳ� ������ ��� ũ�� ������� ���� ���ķ� ����)
			//������ ���� �ϼ�
			if (index_ >= size) {
				is_sorted = true;
			}
			else {

			}

			//�ְ� ��� �� �ּ�ȭ�ϸ鼭 ����
			//���� ���� �� ���ڸ� ����
			if (is_sorted) {
				int temp = int_input[size - 2];
				int_input[size - 2] = int_input[size - 1];
				int_input[size - 1] = temp;
			}
			//�ְ� ��� �ƴ� �� �ְ� ������� ���� ����
			//���� 
			//�ְ���� 1 / �״������� 2 / �״��� ���� 3 ������ ����
			
			//����
			//�Ź� index_�� �����ϸ�(�ڷ� ���鼭)
			//index_�� ���� ���� ū ���ڰ� ������ ����
			//�ڿ��ִ� index_ �� ���� ���� ū ���ڰ� ���� �� �ڿ��ִ� ���ڰ� ������ ������ ���� 
			else {
				while (true) {
					temp_max = 0;
					int start_index_ = index_;
					int max_index_ = 0;
					for (int i = start_index_; i < size; i++) {
						if (temp_max <= int_input[i]) {
							temp_max = int_input[i];
							max_index_ = i;
						}
					}
					if (index_ != max_index_) {
						//���� ����
						int temp = int_input[index_];
						int_input[index_] = int_input[max_index_];
						int_input[max_index_] = temp;
						index_++;
						break;
					}
					else {
						//index�� ũ�Ⱑ ��ü ũ�⺸�� ���� ��� -> �ڷ� �Ѿ�� ���� ������
						if (index_ < size -1) {
							index_++;
							continue;
						}
						//index�� ũ�Ⱑ ��ü ũ��� ���ų� Ŭ��� -> while�� ����
						else {
							break;
						}
					}
				}
			}
			change_count--;
		}

		for (int j = 0; j < size; j++) {
			char temp_char = int_input[j] + '0';
			result[i][j] = temp_char;
		}
		result[i][size] = '\0';
	}


	for (int i = 0; i < 10; i++) {
		cout << "#" << i + 1 << " ";
		printf("%s", result[i]);
		cout << endl;
	}

	return 0;
}