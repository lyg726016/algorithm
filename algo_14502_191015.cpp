#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[8][8] = { 0, };
int wall[8][8] = { 0, };
int n, m;
queue <pair<int, int>> q;
int safe_count = 0;

void simul(){
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	//바이러스 q에 넣음
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (map[i][j] == 2){
				q.push(make_pair(i, j));
			}
		}
	}
	//맵에서 벽만 세움
	int my_map[8][8] = { 0, };
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (wall[i][j] == 1){
				my_map[i][j] = 1;
			}
			if (map[i][j] == 1){
				my_map[i][j] = 1;
			}
		}
	}

	//바이러스 퍼짐
	//my map이랑 비교
	while (!q.empty()){
		pair<int, int> temp = q.front();
		my_map[temp.first][temp.second] = 2;
		q.pop();

		for (int i = 0; i < 4; i++){
			int y = temp.first + dy[i];
			int x = temp.second + dx[i];

			if (x < 0 || y < 0 || y > n - 1 || x > m - 1){
				//do nothing
			}
			else {
				if (my_map[y][x] == 0){
					q.push(make_pair(y, x));
				}
			}
		}
	}
	int s_c = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (my_map[i][j] == 0){
				s_c++;
			}
		}
	}

	if (s_c > safe_count){
		safe_count = s_c;
	}
}


int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	int wall_count = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			
			for (int k = 0; k < n; k++){
				for (int k_ = 0; k_ < m; k_++){

					for (int l = 0; l < n; l++){
						for (int l_ = 0; l_ < m; l_++){
							//if make wall ok
							if (map[i][j] == 0){
								if (wall[i][j] != 1){
									wall[i][j] = 1;
									wall_count++;
								}
							}

							//if make wall ok
							if (map[k][k_] == 0){
								if (wall[k][k_] != 1){
									wall[k][k_] = 1;
									wall_count++;
								}
							}

							//if make wall ok
							if (map[l][l_] == 0){
								if (wall[l][l_] != 1){
									wall[l][l_] = 1;
									wall_count++;
								}
							}

							if (wall_count == 3){
								//시뮬 시작
								simul();
							}

							wall_count = 0;
							memset(wall, 0, sizeof(wall));
						}
					}

				}
			}
		}
	}
	cout << safe_count;
	return 0;
}