#include <iostream>
#include <algorithm>

using namespace std;

int input_y, input_x;
int map[50 + 1][50 + 1];
char temp;
int result[4] = { 0, };
int count_ = 0;

int main() {

	cin >> input_y >> input_x;

	//시작이 b
	//시작이 w

	for (int i = 0; i < input_y; i++) {
		for (int j = 0; j < input_x; j++) {
			cin >> temp;
			map[i][j] = temp;
		}
	}


	return 0;
}