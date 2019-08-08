#include <iostream>
#include <queue>

using namespace std;


struct mp
{
	int x;
	int y;
	int h;
};

int day = 0;;
int input_x;
int input_y;
int input_h;
//map [y][x][h]
int map[101][101][101];
queue <mp> q;

int current_x;
int current_y;
int current_h;

int count_left_tomato;
mp current_point;
mp next_point;
int q_size;

//��ü �ʿ��� �����ִ� �������� �丶�� ���� ���
int search_map() {
	int left_ = 0;
	for (int i = 0; i < input_h; i++) {
		for (int j = 0; j < input_y; j++) {
			for (int k = 0; k < input_x; k++) {
				if (map[j][k][i] == 0) {
					left_++;
				}
			}
		}
	}
	return left_;
}


void solve() {
	//�丶�� �������� ������ ���� ���
	if(!count_left_tomato) {
		cout << day;
		return;
	}
	q_size = q.size();

	//���� ť���ִ� ��� ��ǥ�� ���� �� �� �ִ��� Ȯ�� �� �� �� ������ ť�� ����
	while (q_size) {
		current_point = q.front();
		current_x = current_point.x;
		current_y = current_point.y;
		current_h = current_point.h;

		q.pop();
		q_size--;

		//�Ʒ�
		if (current_h > 0) {
			if (map[current_y][current_x][current_h - 1] == 0) {
				next_point.x = current_x;
				next_point.y = current_y;
				next_point.h = current_h - 1;

				map[next_point.y][next_point.x][next_point.h] = 1;
				count_left_tomato--;
				q.push(next_point);
			}
		}
		//��
		if (current_h < input_h - 1) {
			if (map[current_y][current_x][current_h + 1] == 0) {
				next_point.x = current_x;
				next_point.y = current_y;
				next_point.h = current_h + 1;

				map[next_point.y][next_point.x][next_point.h] = 1;
				count_left_tomato--;
				q.push(next_point);
			}
		}
		//��
		if (current_x > 0) {
			if (map[current_y][current_x - 1][current_h] == 0) {
				next_point.x = current_x - 1;
				next_point.y = current_y;
				next_point.h = current_h;

				map[next_point.y][next_point.x][next_point.h] = 1;
				count_left_tomato--;
				q.push(next_point);
			}
		}
		//��
		if (current_x < input_x - 1) {
			if (map[current_y][current_x + 1][current_h] == 0) {
				next_point.x = current_x + 1;
				next_point.y = current_y;
				next_point.h = current_h;

				map[next_point.y][next_point.x][next_point.h] = 1;
				count_left_tomato--;
				q.push(next_point);
			}
		}
		//��
		if (current_y > 0) {
			if (map[current_y - 1][current_x][current_h] == 0) {
				next_point.x = current_x;
				next_point.y = current_y - 1;
				next_point.h = current_h;

				map[next_point.y][next_point.x][next_point.h] = 1;
				count_left_tomato--;
				q.push(next_point);
			}
		}
		//��
		if (current_y < input_y - 1) {
			if (map[current_y + 1][current_x][current_h] == 0) {
				next_point.x = current_x;
				next_point.y = current_y + 1;
				next_point.h = current_h;

				map[next_point.y][next_point.x][next_point.h] = 1;
				count_left_tomato--;
				q.push(next_point);
			}
		}
	}

	//�丶�䰡 ��������
	if (count_left_tomato) {
		//���� ���� ���� -> ����
		if (!q.size()) {
			cout << -1;
			return;
		}
		//���� ���� ���� -> ����
		else {
			day++;
			solve();
			return;
		}
	}

	//�丶�䰡 �������� ���� �� ����ϰ� ����.
	else {
		cout << day + 1;
		return;
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> input_x >> input_y >> input_h;

	for (int i = 0; i < input_h; i++) {
		for (int j = 0; j < input_y; j++) {
			for (int k = 0; k < input_x; k++) {
				cin >> map[j][k][i];
			}
		}
	}

	//0�� ��������
	//1�� ����
	//-1�� �丶�䰡 ���� ĭ

	//start -> q push
	//���� �丶��(1) q�� ����
	for (int i = 0; i < input_h; i++) {
		for (int j = 0; j < input_y; j++) {
			for (int k = 0; k < input_x; k++) {
				if (map[j][k][i] == 1) {
					mp _mp;
					_mp.x = k;
					_mp.y = j;
					_mp.h = i;
					q.push(_mp);
				}
			}
		}
	}
	//count tomato
	count_left_tomato = search_map();

	//����
	solve();

	return 0;
}