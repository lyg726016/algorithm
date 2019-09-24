#include <string>
#include <vector>

using namespace std;

int get_max_length(vector<int> input) {

}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;

	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] >= n) {
			return 1;
		}
	}



	

	return answer;
}
//#include <string>
//#include <vector>
//
//using namespace std;
//
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//	bool answer = true;
//
//	//int key_size = key.size();
//
//
//	//int valid_size[61][61] = { 0, };
//
//	//for (int i = 0; i < 61; i++) {
//	//	for (int j = 0; j < 61; j++) {
//	//		//초기화
//	//		valid_size[61][61] = { 0, };
//
//	//		//00 ~ 6161 까지 맵 그림
//	//		//0도 90도 180도 270도 각각 회전 - 4
//
//	//		for (int l = 0; l < lock.size(); l++) {
//	//			for (int m = 0; m < lock.size(); m++) {
//	//				if (valid_size[i][j] == lock[l][m]) {
//	//					continue;
//	//				}
//	//				else {
//
//	//				}
//	//			}
//	//		}
//
//	//	}
//	//}
//
//	////모든 가능 좌표 표시
//
//	//
//	//
//
//	////이동 -> 오른
//	////오른 아래
//	////오른 위
//
//	////왼
//
//	////왼 위
//	////왼 아래
//
//	////위
//
//	////위 오
//	////위 좌
//
//	////아래
//	////아래 우
//	////아래 좌
//
//
//
//	return answer;
//}