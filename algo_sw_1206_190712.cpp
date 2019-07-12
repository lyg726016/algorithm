#include <iostream>

using namespace std;

//map[height][width]
//map[y][x]
int map[256][1001];
int T = 10;
//각 T에 대해 조망권 확보된 가구의 수
int result[10];

int main() {

	int max_x = 0;
	int current_heght = 0;

	for (int i = 0; i < T; i++) {
		//결과 담을 배열 초기화
		result[i] = 0;

		//각 건물의 가로
		cin >> max_x;

		for (int j = 0; j < max_x; j++) {
			//width 만큼 높이 입력 받음
			cin >> current_heght;

			for (int k = 0; k < 256; k++) {
				//각 좌표에 대해서 0으로 초기화
				map[k][j] = 0;
				if (k <= current_heght) {
					//입력받은 높이만큼 1로 건물 표시
					map[k][j] = 1;
				}
			}
		}
		
		//조망권 확보 확인
		//각 건물에 대해서
		for (int j = 0; j < max_x - 2; j++) {
			for (int k = 0; k < 256; k++) {
				//현재의 위치에 건물이 있는 경우만 조망권 확인
				if (map[k][j] == 1) {
					//좌우 1칸, 2칸 모두 0인경우 -> 조망권 
					if (map[k][j - 1] == 0 && map[k][j + 1] == 0) {
						if (map[k][j - 2] == 0 && map[k][j + 2] == 0) {
							result[i]++;
						}
					}
				}
			}
		}
	}



	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << result[i - 1] << endl;
	}

	return 0;
}