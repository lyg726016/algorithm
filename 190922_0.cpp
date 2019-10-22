#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int c_m;
int c_c;
int s_m = 0;
deque <int> dq;

//ť�� �� ��Ŵ

//�� ���� ť Ȯ��

//���� �۾�Ȯ��

//�۾��� 1/ ���� �� 0
int is_q_running[11] = { 0, };
//�۾� �� 1/�۾� �� 0 /�۾� �ʿ� 2
int is_m_running[11] = { 2, };
//�۾�
int a_j[11];
//ť�� �۾����� �޽��� �ε�����ȣ
int q_i[11] = { 0, };

int main(void) {
	cin >> c_m >> c_c;

	for (int i = 0; i < c_m; i++){
		int temp;
		cin >> temp;
		a_j[i] = temp;
		is_m_running[i] = 2;
	}
	int time = 1;
	while (true){
		//ť�߿� ��� ť Ȯ��
		for (int k = 0; k < c_c; k++){
			//��� ť ������
			if (is_q_running[k] == 0){
				//���� ���� ó���� ��Ŵ
				for (int j = 0; j < c_m; j++){
					//�ؾߵ� �� -> ������, ť ���������� ����
					if (is_m_running[j] == 2){
						//�ش� �� ���� ������ ����
						is_m_running[j] = 1;
						//�ش� ť ���ϴ� ������ ����
						is_q_running[k] = 1;
						//�ش� ť�� ó���ϴ� �޽��� �ε��� ����
						q_i[k] = j;
						break;
					}
				}
			}
		}
		//���� ���� ť �۾� ����
		for (int q = 0; q < c_c; q++){
			if (is_q_running[q] == 1){
				a_j[q_i[q]] = a_j[q_i[q]] - 1;
				//�� �Ϸ� ��, �Ϸ�� ����
				if (a_j[q_i[q]] <= 0){
					is_m_running[q_i[q]] = 0;
					//ť �ٽ� �۾� 
					is_q_running[q] = 0;
				}
			}
		}

		//�۾� �� ������ Ȯ��
		bool is_all_done = true;
		for (int w = 0; w < c_m; w++){
			if (a_j[w] > 0){
				is_all_done = false;
			}
		}

		//�� ������ �� �ð� ���
		if (is_all_done){
			cout << time;
			break;
		}
		time++;
	}
	return 0;
}