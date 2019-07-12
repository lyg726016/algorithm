#include <iostream>

using namespace std;

int T;

int main() {
	for (int i = 0; i < T; i++) {
		bool temp_is_sorted = true;
		//정렬여부
		is_sorted = false;
		//현재까지 정렬 위치
		index_ = 0;

		cin >> string_input;

		//변환

		int size = strlen(string_input);
		//종료
		//주어진 정수가 한개면 종료
		if (size == 1) {
			temp_result[i] = string_input[0];
			break;
		}

		//변환 각 char -> integer
		for (int i = 0; i < size; i++) {
			char change = string_input[i];
			char * pointer_change = &change;
			//변환 완료.
			int_input[i] = atoi(pointer_change);
		}
		//횟수에 따라서 숫서 변경 시작
		cin >> change_count;

	return 0;
}