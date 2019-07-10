#include <iostream>

using namespace std;

#define MAX_HIT 20
#define MAX_HP 61
#define MAX_COUNT_SCV 3

#define F_D 9
#define S_D 3
#define T_D 1

int info_scv_hp[MAX_HP][MAX_HP][MAX_HP];
int count_scv = 0;
int info_input_scv_hp[3];

int get_min(int input_a, int input_b) {
	return input_a >= input_b ? input_a : input_b;
}

void set_info_scv_hp() {

}

int main() {

	info_scv_hp[0][0][0] = 0;
	set_info_scv_hp();

	cin >> count_scv;

	for (int i = 0; i < MAX_COUNT_SCV; i++) {
		info_input_scv_hp[i] = 0;
	}
	for (int i = 0; i < count_scv; i++)
		cin >> info_input_scv_hp[i];

	cout << info_scv_hp[info_input_scv_hp[0]][info_input_scv_hp[1]][info_input_scv_hp[2]];

	return 0;
}