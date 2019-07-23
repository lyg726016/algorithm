#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

//완전 탐색

#define MAX_N = 999999;

int mx;
int length;

// // MAX_N, 6!
// bool visited[MAX_N+1][720+1] = {0,};

set<pair<int, int>> visited;

//입력받은 수의 길이
//10의 n승으로 나눴을 때 0이됐을 때, n-1이 해당 입력받은 수의 자리수
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
	//a의 자릿값 -> 인덱스 번호 (1 = 0승)
	int ten_a = pow(10, a - 1);
	//b의 자릿값
	int ten_b = pow(10, b - 1);
	//숫자 / 10의 n승  -> 해당 자리의 숫자값 구하기
	int num_a = (num / ten_a) % 10;
	int num_b = (num / ten_b) % 10;

	//해당 자리 끼리 숫자 교환
	num -= num_a*ten_a;
	num -= num_b*ten_b;

	num += num_a*ten_b;
	num += num_b*ten_a;

	return num;
}

//find max -> 방문 시 패스, 방문 안했을 시 각 자리를 변경하며 모든 값 고려
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