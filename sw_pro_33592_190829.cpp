//#include <vector>
//using namespace std;
//
//int solution(vector<int> nums)
//{
//	int answer = 0;
//	int possible_n = nums.size() / 2;
//	int kind_of_p[200001] = { 0, };
//	int max_kind = 0;
//
//	for (int i = 0; i < nums.size(); i++) {
//		kind_of_p[nums[i]] = 1;
//	}
//
//	for (int i = 0; i < 200000; i++) {
//		if (kind_of_p[i] > 0) {
//			max_kind++;
//		}
//	}
//
//	if (possible_n < max_kind) {
//		answer = possible_n;
//	}
//	else {
//		answer = max_kind;
//	}
//
//	return answer;
//}
//
//int main() {
//
//
//
//	return 0;
//}

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

bool checker(int left_count) {
	//���� ������ ���ں� ������ k������ ������ ���� ���� ��ȯ
}


int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue < int , vector<int>, less >> pq;

	int size = scoville.size();
	sort(scoville.begin(), scoville.end(), sizeof(scoville));

	while (scoville.size() > 1) {

		if (scoville.size() == 1) {
			scoville[0]
		}
	}


	return answer;
}

int main() {

	return 0;
}