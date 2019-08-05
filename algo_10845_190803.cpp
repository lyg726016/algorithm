#include <iostream>

using namespace std;

int count_command;
char arr_command[10];
int input_a;

int arr_q[10001];
int head = 0;
int tail = 0;
int q_size = 0;

void solve(){
	//push
	if (arr_command[1] == 'u'){
		q_size++;
		cin >> input_a;
		arr_q[tail++] = input_a;
	}
	//front
	if (arr_command[1] == 'r'){
		if (q_size < 1){
			cout << "-1" << '\n';
		}
		else{
			cout << arr_q[head] << '\n';
		}
	}
	//pop
	if (arr_command[1] == 'o'){
		if (q_size < 1){
			cout << "-1" << '\n';
		}
		else{
			q_size--;
			cout << arr_q[head++] << '\n';
		}
	}
	//back
	if (arr_command[1] == 'a'){
		if (q_size < 1){
			cout << "-1" << '\n';
		}
		else{
			cout << arr_q[tail -1] << '\n';
		}
	}
	//empty
	if (arr_command[1] == 'm'){
		if (q_size < 1) cout << "1" << '\n';
		else cout << "0" << '\n';
	}
	//size
	if (arr_command[1] == 'i'){
		cout << q_size << '\n';
	}
}

int main(){
	cin >> count_command;

	for (int i = 0; i < count_command; i++){
		cin >> arr_command;
		solve();
	}

	return 0;
}