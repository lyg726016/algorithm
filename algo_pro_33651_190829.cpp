//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(int brown, int red) {
//	vector<int> answer;
//
//	for (int i = 1; i < 2500; i++) {
//		for (int j = 1; j <= i; j++) {
//			if (i * 2 + (j - 2) * 2 == brown) {
//				if ((i * j) == (brown + red)) {
//					answer.push_back(i);
//					answer.push_back(j);
//				}
//			}
//		}
//	}
//	return answer;
//}


#/*include <string>
#include <vector>
#include <queue>

using namespace std;

vector <string> p_result;
queue <string> q;

int visit_[10] = { 0 , };

void set_result(int count, int idx) {
	if (count == 3) {
		string temp = "";
		for (int i = 1; i < 10; i++) {
			if (visit_[i] == 1) {
				temp += to_string(i);
			}
		}
		q.push(temp);
		return;
	}

	visit_[idx] = 1;
	set_result(count + 1, idx + 1);
	visit_[idx] = 0;
	set_result(count, idx + 1);
}

void filtering(vector<vector<int>> input) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < q.size(); j++) {
			string temp = q.front();
			q.pop();

			int i_temp = input[i][0];
			string s_temp = to_string(i_temp);
		}
	}
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	set_result(0, 1);
	filtering(baseball);

	return answer;
}*/