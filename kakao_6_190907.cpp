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
//	//		//�ʱ�ȭ
//	//		valid_size[61][61] = { 0, };
//
//	//		//00 ~ 6161 ���� �� �׸�
//	//		//0�� 90�� 180�� 270�� ���� ȸ�� - 4
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
//	////��� ���� ��ǥ ǥ��
//
//	//
//	//
//
//	////�̵� -> ����
//	////���� �Ʒ�
//	////���� ��
//
//	////��
//
//	////�� ��
//	////�� �Ʒ�
//
//	////��
//
//	////�� ��
//	////�� ��
//
//	////�Ʒ�
//	////�Ʒ� ��
//	////�Ʒ� ��
//
//
//
//	return answer;
//}