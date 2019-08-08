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

//전체 맵에서 남아있는 익지않은 토마토 갯수 출력
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
	//토마토 남아있지 않으면 일자 출력
	if(!count_left_tomato) {
		cout << day;
		return;
	}
	q_size = q.size();

	//현재 큐에있는 모든 좌표에 대해 갈 수 있는지 확인 후 갈 수 있으면 큐에 넣음
	while (q_size) {
		current_point = q.front();
		current_x = current_point.x;
		current_y = current_point.y;
		current_h = current_point.h;

		q.pop();
		q_size--;

		//아래
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
		//위
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
		//좌
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
		//우
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
		//전
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
		//후
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

	//토마토가 남아있음
	if (count_left_tomato) {
		//다음 진행 못함 -> 종료
		if (!q.size()) {
			cout << -1;
			return;
		}
		//다음 진행 가능 -> 진행
		else {
			day++;
			solve();
			return;
		}
	}

	//토마토가 남아있지 않을 시 출력하고 종료.
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

	//0은 익지않은
	//1은 익은
	//-1은 토마토가 없는 칸

	//start -> q push
	//익은 토마도(1) q에 삽입
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

	//시작
	solve();

	return 0;
}