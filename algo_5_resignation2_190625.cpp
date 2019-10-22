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



	//����
	//7
	n -= 1;

	//1~7
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		cin >> money[i];
	}

	//���� ��
	if (time[n] > 1) {
		max_profit[n] = 0;
	}
	else {
		max_profit[n] = money[n];
	}

	for (int i = n - 1; i >= 1; i--) {
		//������ �ҿ�ð��� �Ⱓ �ʰ� ��
		if (time[i] + i > n + 1) {
			max_profit[i] = max_profit[i + 1];
		}
		//������ �ҿ�ð��� �Ⱓ �ʰ� ���� ��
		else {
			//���� ���� �߰� ���� ��
			//���� ���� ������ �������� �� ���� ���� ��
			if ((i + time[i]) < (n + 1)) {
				//�̵� -> �߰�
				if (max_profit[i + time[i]] + money[i] > max_profit[i + 1])
					max_profit[i] = max_profit[i + time[i]] + money[i];
				//���� -> �߰� ����
				else
					max_profit[i] = max_profit[i + 1];
			}
			else {
				//���� ���� ������ �������� ���� ��
				if ((i + time[i]) == (n + 1)) {
					//�̵� -> �߰�
					if (max_profit[i + 1] < money[i]) {
						max_profit[i] = money[i];
					}
					//���� -> �߰� ����
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