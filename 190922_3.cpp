#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional>

using namespace std;

//DP
//BFS
//DFS
//BF - ����ġ�� IF ��ø
//STACK
//QUEUE
//PRIORITY QUEUE
//��������
//��Ʈ��ŷ - ����, ����
//�ִܰ��



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