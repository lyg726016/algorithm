#include <iostream>

using namespace std;

int T;

int main() {
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

	return 0;
}