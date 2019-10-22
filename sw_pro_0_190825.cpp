#include <string>
#include <vector>
#include <iostream>

using namespace std;

int i;

string solution(vector<string> seoul) {
	string answer = "";
	string temp_answer;
	string s_temp;
	for (i = 0; i < seoul.size(); i++){
		s_temp = seoul.at(i);
		if (s_temp == "Kim"){
			answer = "김서방은 " + to_string(i) + "에 있다";
				return answer;
		}
	}
}

int main(){
	vector <int> aa = solution(123456);

	for (int i = 0; i < aa.size(); i++){
		cout << aa.at(i);
	}
}