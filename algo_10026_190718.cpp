#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int input_size;
//char -> ������ '\0'
//MAX + 1�� ����.
char map_sm[100 +1][100 +1];
char map_not_sm[100 +1][100 +1];


#define RED 'R'
#define BLUE 'B'
#define GREEN 'G'
#define DONE 'Y'

//result
int count_not_sm = 0;
int count_sm = 0;

queue <pair<int, int>> s_not_sm;
queue <pair<int, int>> s_sm;
char input_c;

char current_color_sm;
char current_color_not_sm;

//�̹� ���� �Ϸ� �� Y�� ����
//����� ��� ���ÿ� ����
//���ÿ� ��� �ְ� �� ���� ��� ���鼭 Y�� ���� -> ������ ���� �ִ� ��� �� ���ÿ� ����



int main() {
	cin >> input_size;

	for (int i = 0; i < input_size; i++) {
		for (int j = 0; j < input_size; j++) {
			cin >> input_c;

			map_not_sm[i][j] = input_c;

			if (input_c == RED || input_c == GREEN)
				map_sm[i][j] = RED;
			else {
				map_sm[i][j] = input_c;
			}
		}
	}

	for (int i = 0; i < input_size; i++) {
		for (int j = 0; j < input_size; j++) {
			if (map_not_sm[i][j] != DONE) {

				s_not_sm.push(make_pair(i, j));

				count_not_sm++;

				current_color_not_sm = map_not_sm[i][j];

				map_not_sm[i][j] = DONE;
			}


			if (map_sm[i][j] != DONE) {

				s_sm.push(make_pair(i, j));

				count_sm++;

				current_color_sm = map_sm[i][j];

				map_sm[i][j] = DONE;
			}

			while (!s_not_sm.empty()) {

				pair <int, int> current_not_sm = s_not_sm.front();
				s_not_sm.pop();

				//�����¿� ���� �����ִ� �� Ȯ��
				//��
				if (current_not_sm.first > 0) {
					if (map_not_sm[current_not_sm.first - 1][current_not_sm.second] == current_color_not_sm) {
						s_not_sm.push(make_pair(current_not_sm.first - 1, current_not_sm.second));
						map_not_sm[current_not_sm.first - 1][current_not_sm.second] = DONE;
					}
				}
				//��
				if (current_not_sm.first < input_size - 1) {
					if (map_not_sm[current_not_sm.first + 1][current_not_sm.second] == current_color_not_sm) {
						s_not_sm.push(make_pair(current_not_sm.first + 1, current_not_sm.second));
						map_not_sm[current_not_sm.first + 1][current_not_sm.second] = DONE;
					}
				}

				//��
				if (current_not_sm.second < input_size > 0) {
					if (map_not_sm[current_not_sm.first][current_not_sm.second - 1] == current_color_not_sm) {
						s_not_sm.push(make_pair(current_not_sm.first, current_not_sm.second - 1));
						map_not_sm[current_not_sm.first][current_not_sm.second - 1] = DONE;
					}
				}

				//��
				if (current_not_sm.second < input_size - 1) {
					if (map_not_sm[current_not_sm.first][current_not_sm.second + 1] == current_color_not_sm) {
						s_not_sm.push(make_pair(current_not_sm.first, current_not_sm.second + 1));
						map_not_sm[current_not_sm.first][current_not_sm.second + 1] = DONE;
					}
				}
			}


			while (!s_sm.empty()) {

				pair <int, int> current_sm = s_sm.front();
				s_sm.pop();

				//�����¿� ���� �����ִ� �� Ȯ��
				//��
				if (current_sm.first > 0) {
					if (map_sm[current_sm.first - 1][current_sm.second] == current_color_sm) {
						s_sm.push(make_pair(current_sm.first - 1, current_sm.second));
						map_sm[current_sm.first - 1][current_sm.second] = DONE;
					}
				}
				//��
				if (current_sm.first < input_size - 1) {
					if (map_sm[current_sm.first + 1][current_sm.second] == current_color_sm) {
						s_sm.push(make_pair(current_sm.first + 1, current_sm.second));
						map_sm[current_sm.first + 1][current_sm.second] = DONE;
					}
				}

				//��
				if (current_sm.second < input_size > 0) {
					if (map_sm[current_sm.first][current_sm.second - 1] == current_color_sm) {
						s_sm.push(make_pair(current_sm.first, current_sm.second - 1));
						map_sm[current_sm.first][current_sm.second - 1] = DONE;
					}
				}

				//��
				if (current_sm.second < input_size - 1) {
					if (map_sm[current_sm.first][current_sm.second + 1] == current_color_sm) {
						s_sm.push(make_pair(current_sm.first, current_sm.second + 1));
						map_sm[current_sm.first][current_sm.second + 1] = DONE;
					}
				}
			}
		}
	}

	cout << count_not_sm << " " << count_sm;

	return 0;
}