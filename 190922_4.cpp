#include <iostream>

using namespace std;

long long map[25][25] = { 0, };


int main(void) {

	int m_x, m_y;
	int c_x, c_y;

	cin >> m_x;
	cin >> m_y;
	cin >> c_x;
	cin >> c_y;

	if (c_x > m_x || c_y > m_y){
		cout << "fail";
	}
	else{
		for (int i = 0; i < 25; i++){
			map[i][0] = 1;
			map[0][i] = 1;
		}

		for (int i = 0; i < c_y + 1; i++){
			for (int j = 0; j < c_x + 1; j++){
				if (i == 0 || j == 0){
					continue;
				}
				else{
					map[i][j] = map[i - 1][j] + map[i][j - 1];
				}
			}
		}
		cout << c_x + c_y << '\n';
		cout << map[c_y][c_x];
	}
}