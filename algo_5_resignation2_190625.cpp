#include <iostream>

using namespace std;

int * time;
int * money;
int n;
int * max_profit;

int main() {
	cin >> n;
	//1~n
	//8
	n += 1;

	time = new int[n];
	money = new int[n];
	max_profit = new int[n];



	//복구
	//7
	n -= 1;

	//1~7
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		cin >> money[i];
	}

	//시작 값
	if (time[n] > 1) {
		max_profit[n] = 0;
	}
	else {
		max_profit[n] = money[n];
	}

	for (int i = n - 1; i >= 1; i--) {
		//현재일 소요시간이 기간 초과 시
		if (time[i] + i > n + 1) {
			max_profit[i] = max_profit[i + 1];
		}
		//현재일 소요시간이 기간 초과 안할 때
		else {
			//현재 일을 추가 했을 때
			//현재 일이 마지막 날까지의 일 보다 작을 때
			if ((i + time[i]) < (n + 1)) {
				//이득 -> 추가
				if (max_profit[i + time[i]] + money[i] > max_profit[i + 1])
					max_profit[i] = max_profit[i + time[i]] + money[i];
				//손해 -> 추가 안함
				else
					max_profit[i] = max_profit[i + 1];
			}
			else {
				//현재 일이 마지막 날까지의 일일 때
				if ((i + time[i]) == (n + 1)) {
					//이득 -> 추가
					if (max_profit[i + 1] < money[i]) {
						max_profit[i] = money[i];
					}
					//손해 -> 추가 안함
					else
						max_profit[i] = max_profit[i + 1];
				}
			}
		}
	}

	cout << max_profit[1];

	delete[] time;
	delete[] money;
	delete[] max_profit;

	return 0;
}