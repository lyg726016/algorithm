#include <iostream>

using namespace std;

//https://www.acmicpc.net/problem/12869

#define MAX_HIT 21
#define MAX_HP 61

#define FIRST_D 9
#define SECOND_D 3
#define THIRD_D 1

#define DEFAULT 31
#define MAX_COUNT_SCV 20

//hit count array
//hit count / a_hp / b_hp / c_hp
int hit_count_array[MAX_HP + FIRST_D][MAX_HP + FIRST_D][MAX_HP + FIRST_D];
int count_scv = 0;
int input_scv[3];

int get_min(int input_a, int input_b) {
	return input_a <= input_b ? input_a : input_b;
}

//각각에 좌표에 +1 ~  +9 / +3 / +1까지 => hit_count++
void set_input_scv(int input_a, int input_b, int input_c) {
	for (int i = 0; i <= FIRST_D; i++) {
		for (int j = 0; j <= SECOND_D; j++) {
			for (int k = 0; k <= THIRD_D; k++) {
				//6가지 경우
				if (i == 0 && j == 0 && k == 0) {
					//do nothing
				}
				else {
					//기존 +1과 이미 담겨있던 값중 작은값 저장
					hit_count_array[input_a + i][input_b + j][input_c + k] = get_min(hit_count_array[input_a + i][input_b + j][input_c + k], hit_count_array[input_a][input_b][input_c] + 1);
					hit_count_array[input_a + i][input_b + k][input_c + j] = get_min(hit_count_array[input_a + i][input_b + k][input_c + j], hit_count_array[input_a][input_b][input_c] + 1);
					hit_count_array[input_a + j][input_b + i][input_c + k] = get_min(hit_count_array[input_a + j][input_b + i][input_c + k], hit_count_array[input_a][input_b][input_c] + 1);
					hit_count_array[input_a + k][input_b + i][input_c + j] = get_min(hit_count_array[input_a + k][input_b + i][input_c + j], hit_count_array[input_a][input_b][input_c] + 1);
					hit_count_array[input_a + j][input_b + k][input_c + i] = get_min(hit_count_array[input_a + j][input_b + k][input_c + i], hit_count_array[input_a][input_b][input_c] + 1);
					hit_count_array[input_a + k][input_b + j][input_c + i] = get_min(hit_count_array[input_a + k][input_b + j][input_c + i], hit_count_array[input_a][input_b][input_c] + 1);
				}
			}
		}
	}
}

int main() {

	for (int j = 0; j < MAX_HP; j++) {
		for (int k = 0; k < MAX_HP; k++) {
			for (int l = 0; l < MAX_HP; l++) {
				hit_count_array[j][k][l] = DEFAULT;
			}
		}
	}
	hit_count_array[0][0][0] = 0;

	for (int j = 0; j < MAX_HP; j++) {
		for (int k = 0; k < MAX_HP; k++) {
			for (int l = 0; l < MAX_HP; l++) {
				set_input_scv(j, k, l);
			}
		}
	}

	cin >> count_scv;

	for (int i = 0; i < MAX_COUNT_SCV; i++) {
		input_scv[i] = 0;
	}
	for (int i = 0; i < count_scv; i++) {
		cin >> input_scv[i];
	}

	cout << hit_count_array[input_scv[0]][input_scv[1]][input_scv[2]];

	return 0;
}