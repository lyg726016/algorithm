#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	//ù ��° ������ ����
	int num = 666;
	int turn = 1;
	//���� Ž��
	while (1)
	{
		//�ش� ���ڸ� ã�Ҵٸ�
		if (turn == N)
			break;
		num++;
		//�ش� ���ڸ� �����ϰ�
		int copyNum = num;
		string s;
		while (copyNum)
		{
			s += (copyNum % 10 + '0');
			copyNum /= 10;
		}
		copyNum = stoi(s);
		//6�� �������� ���� �ִ��� Ȯ��
		int six = 0;
		while (copyNum)
		{
			int temp = copyNum % 10;
			if (temp == 6)
				six++;
			else if (six < 3)
				six = 0;
			copyNum /= 10;
		}
		//������ �����Ѵٸ�
		if (six >= 3)
			turn++;
	}
	cout << num << "\n";
	return 0;
}