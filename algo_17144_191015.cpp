#include <iostream>
#include <queue>

using namespace std;

int map[51][51] = { 0, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int r, c, t;

int f_d_x, f_d_y;
int s_d_x, s_d_y;
int d_c = 0;


//미세먼지 확산
void run(){
	queue <pair <int, int>> q;

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (map[i][j] > 0){
				q.push(make_pair(i, j));
			}
		}
	}

	int x, y;

	//확산되어서 + 된 값 저장
	int p_my_map[51][51] = { 0, };
	//확산되어서 - 된 값 저장
	int m_my_map[51][51] = { 0, };
	/*
		for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
		my_map[i][j] = map[i][j];
		}
		}*/

	for (int i = 0; i < q.size(); i++){
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){
			x = temp.second + dx[i];
			y = temp.first + dy[i];
			int p_c = 0;
			if (x >= 0 && x <= c - 1 && y >= 0 && y < r - 1){
				if (map[y][x] != -1){
					//확산 받아서 느는 값
					p_my_map[y][x] += (map[temp.first][temp.second] / 5);
					p_c++;
				}
			}
			//확산되서 줄어드는 값
			m_my_map[temp.first][temp.second] -= (map[temp.first][temp.second] / 5) * p_c;
		}
	}
	//결과
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			map[i][j] = map[i][j] + p_my_map[i][j] + m_my_map[i][j];
		}
	}
}

int get_sum(){
	int sum = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (map[i][j] != 0 && map[i][j] != -1){
				sum += map[i][j];
			}
		}
	}
	return sum;
}


//공기 청정기 동작
void run_(){
	// Top purifier
	for (int i = f_d_y - 2; i >= 0; i--) map[i + 1][0] = map[i][0];  // ↓
	for (int i = 0; i < c - 1; i++) map[0][i] = map[0][i + 1];    // ←
	for (int i = 0; i < f_d_y; i++) map[i][c - 1] = map[i + 1][c - 1]; // ↑
	for (int i = c - 2; i >= 0; i--) map[f_d_y][i + 1] = map[f_d_y][i]; // →
	map[f_d_y][0] = -1;

	// Bottom purifier
	for (int i = s_d_y + 1; i < r - 1; i++) map[i][0] = map[i + 1][0];   // ↑
	for (int i = 0; i < c - 1; i++) map[r - 1][i] = map[r - 1][i + 1];  // ←
	for (int i = r - 2; i >= s_d_y; i--) map[i + 1][c - 1] = map[i][c - 1];// ↓
	for (int i = c - 2; i >= 0; i--) map[s_d_y][i + 1] = map[s_d_y][i];   // →
	map[s_d_y][1] = -1;
}

void show_map(){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}


int main(){

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> map[i][j];
			if (map[i][j] == -1){
				if (d_c == 0){
					f_d_y = i;
					f_d_x = j;
				}
				else{
					s_d_y = i;
					s_d_x = j;
				}
			}
		}
	}

	while (t--){
		run();
		run_();
	}

	//show_map();

	int result = get_sum();
	cout << result;


	return 0;
}