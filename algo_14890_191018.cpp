#include <iostream>
#include <cstring>

using namespace std;

int n, l;
int map[101][101];
int result = 0;

//경사로 놓으면서 확인
int temp[101] = { 0, };


//경우의 수
//높아지는 경우
//1 높아지는 경우

//1 초과 높아지는 경우
//가로
int more_than_one_x(int y){
	for (int i = 0; i < n - 1; i++){
		if (abs(map[y][i + 1] - map[y][i]) > 1){
			return 1;
		}
	}
	return 0;
}

int make_wall_x(int y){
	int dif;
	for (int i = 0; i < n - 1; i++){
		if (dif = map[y][i + 1] - map[y][i]){
			//높아지는 경우
			if (dif > 0){
				int c_v = map[y][i];
				//오름 놓을 수 없는 경우 종료
				if (i - (l - 1) < 0){
					return 0;
				}
				//오름 넣어
				for (int j = 0; j < l; j++){
					//평평하지 않은 경우 종료
					if (map[y][i - j] != c_v){
						return 0;
					}
					temp[i - j]++;
				}
			}
			//낮아지는 경우
			if (dif < 0){
				int c_v = map[y][i + 1];
				//내림 놓을 수 없는 경우 종료
				if (i + 1 + (l - 1) > n - 1){
					return 0;
				}
				//오름 넣어
				for (int j = 0; j < l; j++){
					//평평하지 않은 경우 종료
					if (map[y][i + 1 + j] != c_v){
						return 0;
					}
					temp[i + 1 + j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (temp[i] > 1){
			return 0;
		}
	}
	return 1;
}

//세로
int more_than_one_y(int x){
	for (int i = 0; i < n - 1; i++){
		if (abs(map[i + 1][x] - map[i][x]) > 1){
			return 1;
		}
	}
	return 0;
}

int make_wall_y(int x){
	int dif;
	for (int i = 0; i < n - 1; i++){
		if (dif = map[i + 1][x] - map[i][x]){
			//높아지는 경우
			if (dif > 0){
				int c_v = map[i][x];
				//오름 놓을 수 없는 경우 종료
				if (i - (l - 1) < 0){
					return 0;
				}
				//오름 넣어
				for (int j = 0; j < l; j++){
					//평평하지 않은 경우 종료
					if (map[i - j][x] != c_v){
						return 0;
					}
					temp[i - j]++;
				}
			}
			//낮아지는 경우
			if (dif < 0){
				int c_v = map[i + 1][x];
				//내림 놓을 수 없는 경우 종료
				if (i + 1 + (l - 1) > n - 1){
					return 0;
				}
				//오름 넣어
				for (int j = 0; j < l; j++){
					//평평하지 않은 경우 종료
					if (map[i + 1 + j][x] != c_v){
						return 0;
					}
					temp[i + 1 + j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (temp[i] > 1){
			return 0;
		}
	}
	return 1;
}

//낮아지는 경우
//1 낮아지는 경우

//1 미만 낮아지는 경우
int main(){
	cin >> n >> l;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++){
		//가로 검사
		//높이 차이 1 초과
		if (more_than_one_x(i)){
			continue;
		}
		//경사로 놓아야 하는 곳에 경사로 놓음
		memset(temp, 0, sizeof(temp));
		if (make_wall_x(i)){
			result++;
		}
		else{
			//경사로 못 만들어
			continue;
		}
	}

	for (int i = 0; i < n; i++){
		//세로 검사
		if (more_than_one_y(i)){
			continue;
		}
		//경사로 놓아야 하는 곳에 경사로 놓음
		memset(temp, 0, sizeof(temp));
		if (make_wall_y(i)){
			result++;
		}
		else{
			//경사로 못 만들어
			continue;
		}

	}
	cout << result;
	return 0;
}