#include <iostream>
#include <math.h>

//https://www.acmicpc.net/problem/4811

using namespace std;

//�˾� �ִ� ���� 30, 1~30 -> + 1
#define MAX_PILL 30 + 1
#define MAX_TEST_CASE 1000 + 1

int w;
int h;
int n;
int t;
int * count_pill;
long long count_string = 0;

//info_fill[w][h]
long long info_fill[MAX_PILL][MAX_PILL];
int test_case[MAX_TEST_CASE];


//������ ���� �ٸ� ���ڿ��� ����Ǽ� ���
//(w, h) = (w-1, h+1) + (w, h-1)
//if h < 1 ( h = 0 ) ���� ó��, -1 �� ��� ���� ���
//if h == MAX_PILL -1 ���� ó��, +1 �� ��� ���� ���

void set_info_fill() {
	info_fill[1][0] = 1;
	info_fill[2][0] = 2;
	info_fill[3][0] = 5;

	for (int i = 1; i < MAX_PILL; i++) {
		info_fill[0][i] = 1;
	}

	for (int w = 1; w < MAX_PILL; w++) {
		for (int h = 0; h < MAX_PILL; h++) {

			if (h == 0) {
					info_fill[w][h] = info_fill[w - 1][h + 1];
			}
			else {
				if(h != MAX_PILL -1)
					info_fill[w][h] = info_fill[w - 1][h + 1] + info_fill[w][h - 1];
			}
		}
	}
}


int main() {

	//0���� �ʱ�ȭ -> info_fill[0][0]�� 0���� ����
	for (int i = 0; i < MAX_PILL; i++) {
		for (int j = 0; j < MAX_PILL; j++) {
			info_fill[i][j] = 0;
		}
	}

	set_info_fill();

	for (int i = 0; i < MAX_TEST_CASE; i++) {
		int input;
		cin >> input;
		test_case[i] = input;
		if (input == 0) {
			break;
		}
	}

	for (int i = 0; i < MAX_TEST_CASE; i++) {
		if (test_case[i] == 0) {
			break;
		}

		cout << info_fill[test_case[i]][0] << endl;
		count_string = 0;
	}


	return 0;
}