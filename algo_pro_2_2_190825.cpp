#include <iostream>
#include<string>
#include <stack>

using namespace std;

stack <char> s;

int left_count = 0;

void do_(string s){
	int answer = 0;
	for (int i = 0; i < s.length(); i++){
		if (!s.empty()){
			if (s.front() == s.at(i)){
				s.pop_back();
			}
			else
			{
				s.push_back(s.at(i));
			}
		}
	}
}

int solution(string s)
{

	do_(s);
	
	if (s.empty()){
		answer = 1;
	}
	else{
		answer = 0;
	}
	return answer;
}

int main(){

	solution("aaabbbb");

	return 0;
}