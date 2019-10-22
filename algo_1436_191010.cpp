#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	//첫 번째 종말의 숫자
	int num = 666;
	int turn = 1;
	//완전 탐색
	while (1)
	{
		//해당 숫자를 찾았다면
		if (turn == N)
			break;
		num++;
		//해당 숫자를 저장하고
		int copyNum = num;
		string s;
		while (copyNum)
		{
			s += (copyNum % 10 + '0');
			copyNum /= 10;
		}
		copyNum = stoi(s);
		//6이 연속으로 세개 있는지 확인
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
		//조건을 만족한다면
		if (six >= 3)
			turn++;
	}
	cout << num << "\n";
	return 0;
}