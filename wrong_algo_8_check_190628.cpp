#include <iostream>

using namespace std;

//1~50
#define MAX_S 51

//A n, n+1
//B n, n+2
//C n, n+3

//check[출근일자][A개수][B개수][C개수][]
bool check[MAX_S][MAX_S][MAX_S][MAX_S];

char right_check[MAX_S];

char temp_input_char;

int count_input_a = 0;
int count_input_b = 0;
int count_input_c = 0;
int count_input_char = 0;

bool is_b_possible(int index) {
	if (right_check[index - 1] == 'B')
		return false;
	return true;
}

bool is_c_possible(int index) {
	if (right_check[index - 1] == 'C')
		return false;
	if (right_check[index - 2] == 'C')
		return false;
	return true;
}

bool get_check(int day, int count_a, int count_b, int count_c) {
	if (day == 0) {
		if(count_a == 0 && count_b == 0 && count_c == 0)
			return true;
	}
	//right_check[index]에 기록을 위한 index
	int index = count_input_char - day;

	//B,C 확인 불가
	if (index == 0) {
		if (count_a) {
			right_check[index] = 'A';
			get_check(day - 1, count_a - 1, count_b, count_c);
		}
		else {
			return false;
		}
		if (count_b) {
			right_check[index] = 'B';
			get_check(day - 1, count_a, count_b - 1, count_c);
		}
		else {
			return false;
		}
		if (count_c) {
			right_check[index] = 'C';
			get_check(day - 1, count_a, count_b, count_c -1);
		}
		else {
			return false;
		}
	}
	//C 확인 불가
	else if (index == 1) {
		if (count_a) {
			right_check[index] = 'A';
			get_check(day - 1, count_a - 1, count_b, count_c);
		}
		else {
			return false;
		}
		if (count_b) {
			if (is_b_possible(index)) {
				right_check[index] = 'B';
				get_check(day - 1, count_a, count_b - 1, count_c);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		if (count_a) {
			right_check[index] = 'A';
			get_check(day - 1, count_a - 1, count_b, count_c);
		}
		else {
			return false;
		}

		if (count_b) {
			if (is_b_possible(index)) {
				right_check[index] = 'B';
				get_check(day - 1, count_a, count_b - 1, count_c);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}

		if (count_c) {
			if (is_c_possible(index)) {
				right_check[index] = 'C';
				get_check(day - 1, count_a, count_b, count_c - 1);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return false;
}

int main() {

	
	
	//1~50, 50회
	for (int i = 1; i < MAX_S; i++) {
		temp_input_char = getchar();

		if (temp_input_char == 'A') {
			count_input_a++;
			count_input_char++;
		}
		else if (temp_input_char == 'B') {
			count_input_b++;
			count_input_char++;
		}
		else if (temp_input_char == 'C') {
			count_input_c++;
			count_input_char++;
		}
		else
		{
			break;
		}
	}


	

	if (get_check(count_input_char, count_input_a, count_input_b, count_input_c)) {
		cout << right_check;
	}
	else {
		cout << "-1";
	}

	return 0;
}