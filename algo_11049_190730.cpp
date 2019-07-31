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
		//좌측 탐색 했음 -> 좌측 이동 불가능 -> 나머지 모든 우측 탐색 진행
		while (right_index_number <= count_god) {
			temp_b = info_row[index_number] * info_col[index_number] * info_col[right_index_number];
			result[start_index_number] += temp_b;
			right_index_number++;
		}
	}
	else if (start_index_number == count_god) {
		//우측 이동 불가능 -> 나머지 모든 좌측 탐색 진행
		while (left_index_number >= 1) {
			temp_a = info_row[left_index_number] * info_col[left_index_number] * info_col[index_number];
			result[start_index_number] += temp_a;
			right_index_number--;
		}
	}
	else {
		while (is_going) {
			//탐색
			if (!is_calculated[left_index_number] && !is_calculated[right_index_number]) {
				temp_a = info_row[left_index_number] * info_col[left_index_number] * info_col[index_number];
				temp_b = info_row[index_number] * info_col[index_number] * info_col[right_index_number];

				//우측이 더 작음 -> 우측 이동
				if (temp_a > temp_b) {
					result[start_index_number] += temp_b;
					right_index_number++;
					is_calculated[right_index_number] = 1;
				}
				//좌측이 더 작음 -> 좌측 이동
				else {
					result[start_index_number] += temp_a;
					left_index_number++;
					is_calculated[left_index_number] = 1;
				}
			}
			else if (is_calculated[left_index_number] == 1) {
				//좌측 탐색 했음 -> 좌측 인덱스 이동 가능 시 이동
				if (left_index_number > 1) {
					left_index_number--;
				}
				//좌측 탐색 했음 -> 좌측 이동 불가능 -> 나머지 모든 우측 탐색 진행
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
				//우측 탐색 했음 -> 우측 인덱스 이동 가능 시 이동
				if (left_index_number < count_god) {
					left_index_number++;
				}
				//우측 이동 불가능 -> 나머지 모든 좌측 탐색 진행
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
				//예외 -> ??
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