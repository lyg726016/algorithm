#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int s_length = s.length();
	int min_result = 10000;

	for (int i = 1; i <= s_length / 2 + 1; i++) {
		//자를 경우의 수
		int cut_size = i;
		int multi_num = s_length / cut_size;
		int temp_length = s_length;
		string checker = "";

		//자르기 시작 -> 마지막 이전까지 자름
		for (int j = 1; j < multi_num; j++) {
			string temp_first = "";
			string temp_second = "";
			//제일 앞 인덱스부터 시작
			for (int k = (j - 1) * cut_size; k < j * cut_size; k++) {
				temp_first += s[k];
			}
			//뒤는 버림
			for (int l = j * cut_size; l < (j + 1) * cut_size; l++) {
				temp_second += s[l];
			}
			//반복 확인
			if (temp_first == temp_second) {
				//3번 연속여부 확인
				if (checker == temp_second) {
					temp_length = temp_length - cut_size;
				}
				else {
					temp_length = temp_length - cut_size + 1;
				}
			}
			checker = temp_first;
		}

		if (min_result > temp_length) {
			min_result = temp_length;
		}
	}

	answer = min_result;
	return answer;
}