#include <iostream>
#include <string>

using namespace std;

int front_sum = 0;
int back_sum = 0;
string input_s;
string s_temp;
int i_temp;
bool is_first_minus = true;
bool is_first_plus = true;

int main(){

	cin >> input_s;

	for (int i = 0; i < input_s.length(); i++){
		//숫자 계산
		if (input_s[i] >= '0' && input_s[i] <= '9'){
			s_temp += input_s[i];
		}
		//부호에 따라 앞, 뒤에 더함
		else if (input_s[i] == '-'){
			if (is_first_minus){
				is_first_minus = false;
				front_sum += stoi(s_temp);
				s_temp = "";
			}
			else{
				back_sum += stoi(s_temp);
				s_temp = "";
			}
		}
		//부호에 따라 앞, 뒤에 더함
		else{
			if (is_first_minus){
				front_sum += stoi(s_temp);
				s_temp = "";
			}
			else{
				back_sum += stoi(s_temp);
				s_temp = "";
			}
		}
		//마지막 숫자 -> 부호에 따라 앞, 뒤에 더함
		if (i == input_s.length() - 1){
			if (is_first_minus){
				front_sum += stoi(s_temp);
				s_temp = "";
			}
			else{
				back_sum += stoi(s_temp);
				s_temp = "";
			}
		}
	}

	cout << front_sum - back_sum << '\n';

	return 0;
}