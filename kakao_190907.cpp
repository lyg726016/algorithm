#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int s_length = s.length();
	int min_result = 10000;

	for (int i = 1; i <= s_length / 2 + 1; i++) {
		//�ڸ� ����� ��
		int cut_size = i;
		int multi_num = s_length / cut_size;
		int temp_length = s_length;
		string checker = "";

		//�ڸ��� ���� -> ������ �������� �ڸ�
		for (int j = 1; j < multi_num; j++) {
			string temp_first = "";
			string temp_second = "";
			//���� �� �ε������� ����
			for (int k = (j - 1) * cut_size; k < j * cut_size; k++) {
				temp_first += s[k];
			}
			//�ڴ� ����
			for (int l = j * cut_size; l < (j + 1) * cut_size; l++) {
				temp_second += s[l];
			}
			//�ݺ� Ȯ��
			if (temp_first == temp_second) {
				//3�� ���ӿ��� Ȯ��
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