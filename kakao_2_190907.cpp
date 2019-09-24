#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//Á¤»ó
bool r_checker(string p) {
	stack<int> s;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') {
			s.push(1);
		}
		else {
			if (s.empty()) {
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return true;
}

//±ÕÇü
bool b_checker(string p) {
	int l_count = 0;
	int r_count = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') l_count++;
		else r_count++;
	}

	if (l_count == r_count) {
		return true;
	}
	else {
		return false;
	}
}

//2 - u
string get_u(string p) {
	string temp = "";
	for (int i = 0; i < p.length(); i++) {
		temp += p[i];
		if (b_checker(temp)) {
			return temp;
		}
	}
}

//2 - v
string get_v(string p) {
	string temp = "";
	for (int i = 0; i < p.length(); i++) {
		temp += p[i];
		if (b_checker(temp)) {
			temp = "";
			if (i < p.length()) {
				for (int j = i + 1; j < p.length(); j++)
				{
					temp += p[j];
				}
				return temp;
			}
			else {
				return "";
			}
		}
	}
}

//3

string solve(string input_s) {
	string result = "";
	if (input_s == "") {
		return "";
	}

	string u = get_u(input_s);
	string v = get_v(input_s);

	if (r_checker(u)) {
		string tt = solve(v);
		string rr = u + tt;
		return rr;
	}
	else {
		string temp = "";
		temp += '(';
		temp += solve(v);
		temp += ')';

		string tt = "";
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(') {
				tt += ')';
			}
			else {
				tt += '(';
			}
		}
		temp += tt;
		return temp;
	}
}

string solution(string p) {
	string answer = "";

	int s_length = p.length();

	if (s_length == 0) {
		return "";
	}

	if (r_checker(p)) {
		return p;
	}

	else {
		answer = solve(p);
	}

	return answer;
}

int main() {

	cout << solution(")(");
	return 0;
}