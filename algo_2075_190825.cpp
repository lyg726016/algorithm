#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int count_data;
int temp;
//pq �⺻ ��������
priority_queue<int> pq;
int i;
int sq_count_data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> count_data;
	sq_count_data = count_data * count_data;
	while (sq_count_data--){
		cin >> temp;
		//�������� ���� -> ���� ���� ���� ���� ��
		pq.push(-temp);
		//����� ũ�� ���� ���� �� ������
		if (pq.size() > count_data)
			pq.pop();
	}
	//5���� ���� ������ => 5��°�� ū ��
	cout << -pq.top();
	return 0;
}