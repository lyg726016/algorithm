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

	//첫째줄, 전체 사람의 수
	cin >> count_person;

	//둘째줄, 촌수 계산해야 하는 사람의 번호
	//x, y


	//셋째줄, 부모 자식들 간의 관계의 개수


	//넷째줄~, 부모 자식관의 관계
	//x,y -> x는 y의 부모 - 사람별로 부모는 한명

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



	//관계가 전혀 없을 경우 -1
	//관계가 있을 경우 촌수 출력

	return 0;
}