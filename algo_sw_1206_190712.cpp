#include <iostream>

using namespace std;

//map[height][width]
//map[y][x]
int map[256][1001];
int T = 10;
//�� T�� ���� ������ Ȯ���� ������ ��
int result[10];

int main() {

	int max_x = 0;
	int current_heght = 0;

	for (int i = 0; i < T; i++) {
		//��� ���� �迭 �ʱ�ȭ
		result[i] = 0;

		//�� �ǹ��� ����
		cin >> max_x;

		for (int j = 0; j < max_x; j++) {
			//width ��ŭ ���� �Է� ����
			cin >> current_heght;

			for (int k = 0; k < 256; k++) {
				//�� ��ǥ�� ���ؼ� 0���� �ʱ�ȭ
				map[k][j] = 0;
				if (k <= current_heght) {
					//�Է¹��� ���̸�ŭ 1�� �ǹ� ǥ��
					map[k][j] = 1;
				}
			}
		}
		
		//������ Ȯ�� Ȯ��
		//�� �ǹ��� ���ؼ�
		for (int j = 0; j < max_x - 2; j++) {
			for (int k = 0; k < 256; k++) {
				//������ ��ġ�� �ǹ��� �ִ� ��츸 ������ Ȯ��
				if (map[k][j] == 1) {
					//�¿� 1ĭ, 2ĭ ��� 0�ΰ�� -> ������ 
					if (map[k][j - 1] == 0 && map[k][j + 1] == 0) {
						if (map[k][j - 2] == 0 && map[k][j + 2] == 0) {
							result[i]++;
						}
					}
				}
			}
		}
	}



	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << result[i - 1] << endl;
	}

	return 0;
}