#include <iostream>

using namespace std;

int input_n;
int count_room[20000];
int main() {

	count_room[0] = 0;
	count_room[1] = 1; //(i - 1) * 6 + 1;
	count_room[2] = 7; //6ÀÇ 1½Â + 1
	count_room[3] = 19; //6
	count_room[4] = 37;


	for (int i = 2; i < 20000; i++) {
		count_room[i] = count_room[i - 1] + (i - 1) * 6;
	}

	cin >> input_n;


	for (int i = 1; i < 20000; i++) {
		if (input_n <= count_room[i] && input_n >= count_room[i - 1]) {
			cout << i;
			break;
		}
	}
	return 0;
}