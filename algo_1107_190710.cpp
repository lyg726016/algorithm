#include <iostream>

using namespace std;

#define five 100000
#define four 10000
#define three 1000
#define two 100
#define one 10

//�̵��Ϸ��� �ϴ� ä��
int target = 0;
//���峭 ��ư�� ����
int M = 0;
//���峭 ��ư ��ȣ
int number = 0;
//��ư ���� ���� ���� ( 1�̸� ����, 0 �̸� ����)
int B[10];
//���� ä��
int current = 100;
//�ӽð��
int temp_result = 0;
//������� - �� �ڸ� ������ Ƚ�� ����
int result = 0;
//���� ä�� ��ȣ
int current_number = 0;

int get_current_channel(int five, int four, int three, int two, int one, int zero) {

}


int main()
{

	for (int i = 0; i < 10; i++) {
		B[i] = 1;
	}

	cin >> target;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> number;
		B[number] == 0;
	}

	int count_click = 0;

	//���
	//1. �ȴ����� ���
	if (target == 100) {
		cout << count_click;
		return 0;
	}
	//2. ���� ������ ���
	for (int i = 0; i < 10; i++) {
	}

	//3. �߰� ����


	return 0;
}