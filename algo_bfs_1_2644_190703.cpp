#include <iostream>
#include <queue>
//https://www.acmicpc.net/problem/2644

using namespace std;

int count_person;
int persion_a, persion_b;

queue<int> hiarch;
queue <int, int> pair;

#define MAX_PERSON 100+1

int person_array[MAX_PERSON];

int main() {

	for (int i = 0; i < MAX_PERSON; i++) {
		person_array[i] = 0;
	}

	//ù°��, ��ü ����� ��
	cin >> count_person;

	//��°��, �̼� ����ؾ� �ϴ� ����� ��ȣ
	//x, y


	//��°��, �θ� �ڽĵ� ���� ������ ����


	//��°��~, �θ� �ڽİ��� ����
	//x,y -> x�� y�� �θ� - ������� �θ�� �Ѹ�

	/*  
		1 2
		1 3
		2 7
		2 8
		2 9
		4 5
		4 6 
	*/

	// 1 - 2, 3
	// 2 - 7, 8, 9
	// 4 - 5, 6



	//���谡 ���� ���� ��� -1
	//���谡 ���� ��� �̼� ���

	return 0;
}