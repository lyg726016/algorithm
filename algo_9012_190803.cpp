#include <iostream>
#include <cstring>

using namespace std;

int count_input;
char arr_input[51];
int length = 0;

int left_char = 0;

void solve(){

	left_char = 0;

	for (int i = 0; i < 51; i++){
		if (arr_input[i] != '(' && arr_input[i] != ')'){
			length = i;
			break;
		}
	}

	for (int i = 0; i < length; i++){
		if (arr_input[i] == '('){
			left_char++;
		}
		else{
			if (left_char == 0){
				cout << "NO" << '\n';
				return;
			}
			else
			{
				left_char--;
			}
		}
	}
	if (left_char == 0)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

int main(){
	cin >> count_input;

	for (int i = 0; i < count_input; i++){
		//initializing
		memset(arr_input, '0', sizeof(arr_input));

		cin >> arr_input;
		solve();
	}

	return 0;
}