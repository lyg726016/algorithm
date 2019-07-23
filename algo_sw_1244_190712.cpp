#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

//���� Ž��

#define MAX_N = 999999;

int mx;
int length;

// // MAX_N, 6!
// bool visited[MAX_N+1][720+1] = {0,};

set<pair<int, int>> visited;

//�Է¹��� ���� ����
//10�� n������ ������ �� 0�̵��� ��, n-1�� �ش� �Է¹��� ���� �ڸ���
void getLength(int num) {
	int ten = 1;
	for (int i = 1; i < 8; i++) {
		if (num / ten == 0) {
			length = i - 1;
			break;
		}
		ten *= 10;
	}
}

//do 
int swap(int num, int a, int b) {
	//a�� �ڸ��� -> �ε��� ��ȣ (1 = 0��)
	int ten_a = pow(10, a - 1);
	//b�� �ڸ���
	int ten_b = pow(10, b - 1);
	//���� / 10�� n��  -> �ش� �ڸ��� ���ڰ� ���ϱ�
	int num_a = (num / ten_a) % 10;
	int num_b = (num / ten_b) % 10;

	//�ش� �ڸ� ���� ���� ��ȯ
	num -= num_a*ten_a;
	num -= num_b*ten_b;

	num += num_a*ten_b;
	num += num_b*ten_a;

	return num;
}

//find max -> �湮 �� �н�, �湮 ������ �� �� �ڸ��� �����ϸ� ��� �� ���
void start(int num, int cnt) {

	if (cnt == 0) mx = max(mx, num);
	if (cnt < 0) return;
	pair<int, int> tmp = make_pair(num, cnt);
	if (visited.find(tmp) != visited.end()) return;

	visited.insert(make_pair(num, cnt));

	for (int i = 1; i <= length; i++) {
		for (int j = i + 1; j <= length; j++) {
			int n = swap(num, i, j);
			//printf("%d\n",n);
			start(n, cnt - 1);
		}
	}
}


int main() {
	int T, num, cnt;
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		mx = 0;
		scanf("%d %d", &num, &cnt);

		//do
		getLength(num);
		start(num, cnt);

		printf("#%d %d\n", test_case + 1, mx);
	}
	return 0;
}