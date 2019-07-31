#include <iostream>

using namespace std;

// N X N cell
// n 7 12
// core 1 ~ 12
// 연결안되는 core 존재 가능

int T;
int MAP[12][12];
int N;

//각 코어별로 가능여부 파악 함수

int main() {
	cin >> T;


	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> MAP[i][j];
			}
		}

		//core 당 4개의 가지수, 4의 12승 = 2의 24승 = 1024 * 1024 * 16 = 1600만 = 0.16초 * 50 = 8초, 초과
		//dp? greedy?


		//고려조건
		//first : 최대한 많은 core 연결
		//second : 최대한 많을 때, 최소 전선길이

		//연결 가능 여부 파악
		//불가능인 경우 => 가능한 벽까지 전선 연결 중 다른 전선이 있는 경우, 가능한 벽까지 전선 연결 중 다른 core가 있는 경우

		//밖에서부터 제거하면서 선?

		//우선 순위 -> 길이 하나 밖에 없는 코어를 최우선으로

		//map에 전선을 긋는 경우 -> 
		
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				
			}
		}

	}
	return 0;
}