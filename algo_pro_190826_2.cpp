#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp_func(int a, int b) {
	string s_a = to_string(a);
	string s_b = to_string(b);

	if (s_a.length() > s_b.length()) {
		for (int i = 0; i < s_b.length(); i++) {
			if (s_a[i] > s_b[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		for (int i = 0; i < s_a.length(); i++) {
			if (s_a[i] > s_b[i]) {
				return true;
			}
		}
		return false;
	}
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), comp_func);

	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}

int main() {


	return 0;
}