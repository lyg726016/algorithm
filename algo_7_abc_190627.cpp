//https://www.acmicpc.net/problem/12969

#include <iostream>

using namespace std;

//bool dp[���� ���ڿ��� ����][A�� ����][B�� ����][���� ����]
bool dp[31][31][31][436];
char * S;
int N;
int K;

bool solve(int x, int a, int b, int p) {

	// ���� ����
	if (x == N) {
		if (p == K) return true;
		else return false;
	}

	// �湮�߾�����, �ٽ� �湮�ߴٸ� �ش� ���ڿ��� ���� ���̴�. return false;
	if (dp[x][a][b][p]) return false;
	// �湮 ���� üũ
	dp[x][a][b][p] = true;

	// 1. x��° ���Ұ� A�� ���
	// A�� ��� ���� ������ �������� ����(p=p)
	S[x] = 'A';
	if (solve(x + 1, a + 1, b, p)) return true;

	// 2. x��° ���Ұ� B�� ���
	// x��° �տ��ִ� a�� ���� = ���� ������ �߰�(p=p+a)
	S[x] = 'B';
	if (solve(x + 1, a, b + 1, p + a)) return true;

	// 3. x��° ���Ұ� C�� ���
	// x��° �տ��ִ� a�� b�� ���� = ���� ������ �߰�(p=p+a+b)
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