#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional>

using namespace std;

//DP
//BFS
//DFS
//BF - 가지치기 IF 중첩
//STACK
//QUEUE
//PRIORITY QUEUE
//분할정복
//백트레킹 - 수열, 순열
//최단경로



int l_a;
int temp = 0;
int c_t = 0;
int max_t = 0;


int main(){
	cin >> l_a;
	for (int i = 0; i < l_a; i++){
		cin >> temp;
		if (temp == 0){
			c_t++;
			if (max_t < c_t){
				max_t = c_t;
			}
		}
		else{
			c_t = 0;
		}
	}

	if (max_t < 3){
		cout << 1;
	}
	else{
		int result = max_t / 2;

		if (max_t % 2 == 0){
			cout << result;
		}
		else{
			result++;
			cout << result;
		}
	}

	return 0;
}