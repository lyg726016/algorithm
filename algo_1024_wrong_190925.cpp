#include <iostream>
#include <queue>

using namespace std;

int N, L;


int main() {
	cin >> N >> L;

	//�Է��� �� ¦�� -> Ȧ���� ¦���� �϶��� ����
	//Ȧ������ ���� -> Ȧ¦Ȧ, Ȧ¦Ȧ¦, Ȧ¦Ȧ¦Ȧ¦Ȧ, Ȧ¦Ȧ¦Ȧ¦Ȧ¦
	//¦������ ���� -> ¦Ȧ¦Ȧ, ¦Ȧ¦Ȧ¦, ¦Ȧ¦Ȧ¦Ȧ¦Ȧ¦, 

	//�Է��� �� Ȧ��

	//n~ n+3�� �� -> 3n+3
	
	
	//n = ����� �迭���� �ִ��� ��� ��
	//n - 2, n - 1, n, n +1 -> 4n -2
	//�迭�� ���� ¦��
	//2, 4, 6, 8, 10
	//2 = 2n -1
	//4 = 4n -2
	//6 = 6n -3
	//8 = 8n -4
	// => L�� Ȧ���϶��� ����

	//�迭�� ���� Ȧ��
	//n-2, n-1, n, n+1, n+2 -> 5n
	//1, 3, 5, 7, 9
	//3 = 3n
	//5 = 5n
	//7 = 7n
	// => L�� ¦�� Ȧ�� �� ����

	int result_n = 0;

	//n 
	for (int n = 1; n < 200; n++) {
		//�迭�� ����
		for (int j = 2; j < 101; j++) {
			int result;
			if (j % 2 == 0) {
				result = n * j - (j / 2);

				if (result == N) {
					result_n = n;
					return 0;
				}
			}
			else {
				result = n * j;

				if (result == N) {
					for (int k = 0; k < j; k++) {
						result_n = n;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}