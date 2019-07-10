#include <iostream>
#include <string.h>
#include <queue>
#include <set>
#include <stack>
using namespace std;

#define MAX_LENGTH 50

#define A 0
#define B 1
#define C 2

int cache[3][3][MAX_LENGTH + 1][MAX_LENGTH + 1][MAX_LENGTH + 1] = { 0, };
stack<int> s;

bool ps(int mx, int f2) {
	if (mx == 1) {
		s.push(f2);
		return true;
	}
	else {
		return false;
	}
}
//되는놈은 계속 스택에 넣으면서 살고
//안되는 놈은 종료
int possible(int f1, int f2, int cntA, int cntB, int cntC) {
	if (cache[f1][f2][cntA][cntB][cntC] != 0) {
		if (ps(cache[f1][f2][cntA][cntB][cntC], f2)) return 1;
		else return -1;
	}

	int mx = -1;

	if (f1 == A && cntA > 0) {
		if (f2 == A) {
			mx = max(possible(f2, A, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, B, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, C, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
		}
		else if (f2 == B) {
			mx = max(possible(f2, A, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, C, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
		}
		else if (f2 == C) {
			mx = max(possible(f2, A, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, B, cntA - 1, cntB, cntC), mx);
			if (ps(mx, f2)) return mx;
		}

	}
	else if (f1 == B && cntB > 0) {
		if (f2 == A) {
			mx = max(possible(f2, A, cntA, cntB - 1, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, B, cntA, cntB - 1, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, C, cntA, cntB - 1, cntC), mx);
			if (ps(mx, f2)) return mx;
		}
		else if (f2 == C) {
			mx = max(possible(f2, A, cntA, cntB - 1, cntC), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, B, cntA, cntB - 1, cntC), mx);
			if (ps(mx, f2)) return mx;
		}
	}
	else if (f1 == C && cntC > 0) {
		if (f2 == A) {
			mx = max(possible(f2, A, cntA, cntB, cntC - 1), mx);
			if (ps(mx, f2)) return mx;
			mx = max(possible(f2, B, cntA, cntB, cntC - 1), mx);
			if (ps(mx, f2)) return mx;
		}
		else if (f2 == B) {
			mx = max(possible(f2, A, cntA, cntB, cntC - 1), mx);
			if (ps(mx, f2)) return mx;
		}
	}

	cache[f1][f2][cntA][cntB][cntC] = mx;
	return mx;
}


int main() {

	char str[MAX_LENGTH + 5];

	scanf("%s", str);

	char MAX_A = 0;
	char MAX_B = 0;
	char MAX_C = 0;

	int sz = strlen(str);

	for (int i = 0; i < sz; i++) {
		if (str[i] == 'A') MAX_A++;
		if (str[i] == 'B') MAX_B++;
		if (str[i] == 'C') MAX_C++;
	}

	if (MAX_A + MAX_B + MAX_C == 1) {
		printf("%s", str);
		return 0;
	}

	//핵심 - 어떻게보면 지금 이게 키포인트입니다 
	cache[A][A][2][0][0] = 1;
	cache[A][B][1][1][0] = 1;
	cache[A][C][1][0][1] = 1;

	cache[B][A][1][1][0] = 1;
	cache[B][B][0][2][0] = -1;
	cache[B][C][0][1][1] = 1;

	cache[C][A][1][0][1] = 1;
	cache[C][B][0][1][1] = 1;
	cache[C][C][0][0][2] = -1;

	int mx = -1;

	for (int f1 = A; f1 <= C; f1++) {
		for (int f2 = A; f2 <= C; f2++) {
			if (f1 == B && f2 == B) continue;
			if (f1 == C && f2 == C) continue;
			mx = max(possible(f1, f2, MAX_A, MAX_B, MAX_C), mx);
			if (mx == 1) {
				ps(mx, f1);
				break;
			}
		}
		if (mx == 1)break;
	}

	if (mx == 1) {
		while (!s.empty()) {
			printf("%c", s.top() + 'A');
			s.pop();
		}
	}
	else {
		printf("-1");
	}



	return 0;
}