#include <iostream>

using namespace std;




int count_god;
int info_row[501]; //a
int info_col[501]; //b


int result[501] = { 0, };



void start_recursive(int start_index_number) {

	//a, b
	//b, c
	//c, d

	int temp_a; // (ac)(b+d)
	int temp_b; // (bd)(a+c)
	int is_calculated[501] = { 0, };
	int index_number = start_index_number;
	int left_index_number = index_number - 1;
	int right_index_number = index_number + 1;
	int is_going = 1;

	if (start_index_number == 1) {
		//���� Ž�� ���� -> ���� �̵� �Ұ��� -> ������ ��� ���� Ž�� ����
		while (right_index_number <= count_god) {
			temp_b = info_row[index_number] * info_col[index_number] * info_col[right_index_number];
			result[start_index_number] += temp_b;
			right_index_number++;
		}
	}
	else if (start_index_number == count_god) {
		//���� �̵� �Ұ��� -> ������ ��� ���� Ž�� ����
		while (left_index_number >= 1) {
			temp_a = info_row[left_index_number] * info_col[left_index_number] * info_col[index_number];
			result[start_index_number] += temp_a;
			right_index_number--;
		}
	}
	else {
		while (is_going) {
			//Ž��
			if (!is_calculated[left_index_number] && !is_calculated[right_index_number]) {
				temp_a = info_row[left_index_number] * info_col[left_index_number] * info_col[index_number];
				temp_b = info_row[index_number] * info_col[index_number] * info_col[right_index_number];

				//������ �� ���� -> ���� �̵�
				if (temp_a > temp_b) {
					result[start_index_number] += temp_b;
					right_index_number++;
					is_calculated[right_index_number] = 1;
				}
				//������ �� ���� -> ���� �̵�
				else {
					result[start_index_number] += temp_a;
					left_index_number++;
					is_calculated[left_index_number] = 1;
				}
			}
			else if (is_calculated[left_index_number] == 1) {
				//���� Ž�� ���� -> ���� �ε��� �̵� ���� �� �̵�
				if (left_index_number > 1) {
					left_index_number--;
				}
				//���� Ž�� ���� -> ���� �̵� �Ұ��� -> ������ ��� ���� Ž�� ����
				else {
					while (right_index_number <= count_god) {
						temp_b = info_row[index_number] * info_col[index_number] * info_col[right_index_number];
						result[start_index_number] += temp_b;
						right_index_number++;
					}
					is_going = 0;
				}
			}
			else if (is_calculated[right_index_number] == 1) {
				//���� Ž�� ���� -> ���� �ε��� �̵� ���� �� �̵�
				if (left_index_number < count_god) {
					left_index_number++;
				}
				//���� �̵� �Ұ��� -> ������ ��� ���� Ž�� ����
				else {
					while (left_index_number >= 1) {
						temp_a = info_row[left_index_number] * info_col[left_index_number] * info_col[index_number];
						result[start_index_number] += temp_a;
						right_index_number--;
					}
					is_going = 0;
				}
			}
			else {
				//���� -> ??
				break;
			}
		}
	}
}


int main() {
	cin >> count_god;

	for (int i = 1; i < count_god + 1; i++) {
		cin >> info_row[i] >> info_col[i];
	}

	if (count_god == 1) {
		cout << 1;
		return 0;
	}
	else if (count_god == 2) {
		cout << info_row[1] * info_col[1] * info_col[2];
		return 0;
	}


	for (int i = 1; i < count_god + 1; i++) {
		start_recursive(i);
	}

	int min_result = 22222222222;

	for (int i = 1; i < count_god + 1; i++) {
		if (result[i] < min_result) {
			min_result = result[i];
		}
	}

	cout << min_result;

	return 0;
}