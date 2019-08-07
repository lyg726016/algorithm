#include <iostream>

using namespace std;

int input_n;
int input_x;
int input_m;

int cage_start[10];
int cage_end[10];
int total_count[10];

int tc;

int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {

		cin >> input_n >> input_x >> input_m;

		//n개의 우리

		//각 우리당 x마리 이하의 햄스터

		//기록의 개수 m

		//N, X, M(1 ≤ N ≤ 6, 1 ≤ X, M ≤ 10)

		for (int i = 0; i < input_m; i++) {
			//a우리부터 b우리까지 총 c마리의 햄스터
			cin >> cage_start[i] >> cage_end[i] >> total_count[i];
		}

		//출력 조건
		//1 햄스터 수가 가장 많도록
		//2 사전순으로 가장 빠른 것
		//불가능 시 -1 출력

		//a ~ b의 케이지 result__[a][b]의 햄스터 수 합
		int result__[7][7][7][7][7][7];
		

		for(int i = 0; i < )
	}
	return 0;
}