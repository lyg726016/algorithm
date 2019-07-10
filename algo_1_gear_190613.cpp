#include <iostream>
using namespace std;

#pragma warning(disable : 4996)

int gear[4][8];

int remainder(int input) {
	return input % 8;
}

int count(int gear_0, int gear_1, int gear_2, int gear_3) {
	int count = 0;

	if (gear_0)
		count += 1;
	if (gear_1)
		count += 2;
	if (gear_2)
		count += 4;
	if (gear_3)
		count += 8;

	printf("%d", count);
}

int main()
{
	freopen("input.txt", "r", stdin);


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> gear[i][j];
		}
	}
	
	
	int rotation_count;
	cin >> rotation_count;

	//gear
	//1 > 2
	//2 < 6 / 2 > 2
	//3 < 6 / 2 > 2
	//4 < 6 

	int index_of_gear_0 = 0;
	int index_of_gear_1 = 0;
	int index_of_gear_2 = 0;
	int index_of_gear_3 = 0;

	for (int i = 0; i < rotation_count; i++) {
		int gear_number;
		cin >> gear_number;

		if (gear[0][2] == gear[1][6]) {

		}
	}

	//경우의 수 
	
	return 0;//정상종료시 반드시 0을 리턴해야 합니다.
}