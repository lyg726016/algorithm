//https://www.acmicpc.net/problem/12969

#include <iostream>

using namespace std;

//bool dp[현재 문자열의 길이][A의 개수][B의 개수][쌍의 개수]
bool dp[31][31][31][436];
char * S;
int N;
int K;

bool solve(int x, int a, int b, int p) {

	// 종료 조건
	if (x == N) {
		if (p == K) return true;
		else return false;
	}

	// 방문했었지만, 다시 방문했다면 해당 문자열이 없는 것이다. return false;
	if (dp[x][a][b][p]) return false;
	// 방문 여부 체크
	dp[x][a][b][p] = true;

	// 1. x번째 원소가 A인 경우
	// A일 경우 쌍의 개수가 증가하지 않음(p=p)
	S[x] = 'A';
	if (solve(x + 1, a + 1, b, p)) return true;

	// 2. x번째 원소가 B인 경우
	// x번째 앞에있는 a의 개수 = 쌍의 개수에 추가(p=p+a)
	S[x] = 'B';
	if (solve(x + 1, a, b + 1, p + a)) return true;

	// 3. x번째 원소가 C인 경우
	// x번째 앞에있는 a와 b의 개수 = 쌍의 개수에 추가(p=p+a+b)
	S[x] = 'C';
	if (solve(x + 1, a, b, p + a + b)) return true;

	return false;
}

int main() {
	cin >> N >> K;
	S = new char[N];
	S[N] = '\0';

	if (solve(0, 0, 0, 0)) {
		cout << S;
	}
	else {
		cout << "-1";
	}

	return 0;
}