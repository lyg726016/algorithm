#include <iostream>

//0~1011
#define MAX_Y 1011 + 1
#define MAX 1000000

using namespace std;

//�׽�Ʈ���̽�
int t = 0;
//���� Ƚ��
int count_jump = 0;
//�⺻ ��� ��
int base_count_jump = 0;
int base_distance = 0;
//�� ������ �Ÿ�
int *array_jump;
//�ִ� ���� �Ÿ�
int max_jump = 0;
//�� �Ÿ��� ��
int * result;
int current_x = 0;
// ���� ���� �Ÿ�
int * distance_jump;

//���� ���� �� �Ÿ�
void set_distance_jump() {
	distance_jump[0] = 0;
	for (int i = 1; i < MAX +1; i++) {
		distance_jump[i] = distance_jump[i - 1] + i;
	}
}

//get �Ÿ��� �ּ� ����
int get_min_jump(int distance) {

	for (int i = 1; i < MAX; i++) {
		//���� ����
		//���� �Ÿ��� 0�̸� ���� ����
		if (current_x == distance) {
			return count_jump;
		}
		//�̹� �������� ���� �Ÿ��� ��� ����
		if (distance >=  current_x + i) {
			current_x = current_x + i;
			count_jump++;
		}
		//�̹� �������� ���� �Ÿ��� ª���� ���� �ʱ�ȭ �� ÷��
		else {
			i = 1;
			current_x = current_x + i;
			count_jump++;
		}
	}
}

int main() {

	distance_jump = (int *)malloc(sizeof(int) * (MAX + 1));
	int start_x = 0, end_y = 0;
	//�� �Ÿ��� ���� ����Ƚ�� �ӽ� �����
	cin >> t;

	//���
	result = (int *)malloc(sizeof(int) * t);
	for (int i = 0; i < t; i++) {
		//var initializing
		count_jump = 0;
		start_x = 0;

		cin >> start_x >> end_y;

		//10�� 5�� ~ 10�� 6�� => 10�� 5�� ���� ����.
		for (int i = 0; i < MAX; i++) {
			if (start_x < distance_jump[i]) {
				base_count_jump = i - 1;
				base_distance = distance_jump[i - 1];
				break;
			}
		}
		//get max
		max_jump = 0;

		for (int i = 0; i <= end_y - start_x; i++) {
			current_x = 0;
			
			if (max_jump < get_min_jump(i)) {
				max_jump = get_min_jump(i);
			}
		}
		result[i] = max_jump;
	}

	for (int i = 0; i < t; i++)
	{
		printf("Case #%d\n", i + 1);
		printf("%d\n", result[i]);
	}

	return 0;
}