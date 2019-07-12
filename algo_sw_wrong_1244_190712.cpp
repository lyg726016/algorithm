#include <iostream>
#include <string.h>

using namespace std;

int T;
//input -> int로 변환하기 전
char string_input[6] = "";

//사용할 숫자판
int int_input[6];
//변화 횟수
int change_count = 0;
//최고값 출력 여부
bool is_sorted = false;
//현재까지 정렬한 위치
int index_ = 0;
//현재 남은 배열에서 최대 값
int temp_max = 0;

//출력
char result[10][20];
string temp_result[10];

int main() {
	cin >> T;


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

		while (true) {
			//횟수 사용 다함
			if (change_count == 0) {
				break;
			}

			//숫자의 크기가 꼬인 부분이 하나라도 있을 시 정렬 안됨.
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

			
			//정상 정렬 여부 확인(하나하나 돌렸을 경우 크기 상관없이 정상 정렬로 가정)
			//무조건 정렬 완성
			if (index_ >= size) {
				is_sorted = true;
			}
			else {

			}

			//최고 출력 시 최소화하면서 변경
			//가장 뒤의 두 숫자를 변경
			if (is_sorted) {
				int temp = int_input[size - 2];
				int_input[size - 2] = int_input[size - 1];
				int_input[size - 1] = temp;
			}
			//최고 출력 아닐 시 최고 출력으로 정렬 시작
			//정렬 
			//최고숫자 1 / 그다음숫자 2 / 그다음 숫자 3 오도록 변경
			
			//구현
			//매번 index_를 증가하며(뒤로 가면서)
			//index_가 낮을 수록 큰 숫자가 오도록 변경
			//뒤에있는 index_ 중 같은 제일 큰 숫자가 있을 시 뒤에있는 숫자가 앞으로 오도록 변경 
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
						//정렬 진행
						int temp = int_input[index_];
						int_input[index_] = int_input[max_index_];
						int_input[max_index_] = temp;
						index_++;
						break;
					}
					else {
						//index의 크기가 전체 크기보다 작을 경우 -> 뒤로 넘어가서 정렬 재진행
						if (index_ < size -1) {
							index_++;
							continue;
						}
						//index의 크기가 전체 크기와 같거나 클경우 -> while문 종료
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