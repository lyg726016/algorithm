#include <iostream>

using namespace std;

int input_n;
int input_x;
int input_m;

int cage_start[10];
int cage_end[10];
int total_count[10];

int tc;

int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {

		cin >> input_n >> input_x >> input_m;

		//n���� �츮

		//�� �츮�� x���� ������ �ܽ���

		//����� ���� m

		//N, X, M(1 �� N �� 6, 1 �� X, M �� 10)

		for (int i = 0; i < input_m; i++) {
			//a�츮���� b�츮���� �� c������ �ܽ���
			cin >> cage_start[i] >> cage_end[i] >> total_count[i];
		}

		//��� ����
		//1 �ܽ��� ���� ���� ������
		//2 ���������� ���� ���� ��
		//�Ұ��� �� -1 ���

		//a ~ b�� ������ result__[a][b]�� �ܽ��� �� ��
		int result__[7][7][7][7][7][7];
		

		for(int i = 0; i < )
	}
	return 0;
}