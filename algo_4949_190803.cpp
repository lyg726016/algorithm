#include <iostream>
#include <cstring>
#include <stack>
#include <string>

using namespace std;

//char arr_input[101];
int length = 0;
int current_state;
string arr_input;

int solve(){
	//1은 소괄호, 2는 대괄호 open 상황
	stack <int> state;

	for (int i = 0; i < 101; i++){
		if (arr_input[i] == '.'){
			length = i;
			break;
		}
	}

	if (length == 0){
		return 1;
	}

	for (int i = 0; i < length; i++){
		if (arr_input[i] == '('){
			state.push(1);
		}
		if (arr_input[i] == '['){
			state.push(2);
		}
		if (arr_input[i] == ')'){
			if (!state.empty()){
				current_state = state.top();
				if (current_state == 1){
					state.pop();
				}
				else{
					cout << "no" << '\n';
					return 0;
				}
			}
			else{
				cout << "no" << '\n';
				return 0;
			}
		}
		if (arr_input[i] == ']'){
			if (!state.empty()){
				current_state = state.top();
				if (current_state == 2){
					state.pop();
				}
				else{
					cout << "no" << '\n';
					return 0;
				}
			}
			else{
				cout << "no" << '\n';
				return 0;
			}
		}
	}
	if (state.empty()){
		cout << "yes" << '\n';
		return 0;
	}
	else{
		cout << "no" << '\n';
		return 0;
	}
}

int main(){
	while (true){

		//initializing

		getline(cin, arr_input);

		if (solve()){
			return 0;
		}
	}
	return 0;
}