#include <iostream>

using namespace std;

#define five 100000
#define four 10000
#define three 1000
#define two 100
#define one 10

//이동하려고 하는 채널
int target = 0;
//고장난 버튼의 개수
int M = 0;
//고장난 버튼 번호
int number = 0;
//버튼 정상 동작 여부 ( 1이면 정상, 0 이면 고장)
int B[10];
//현재 채널
int current = 100;
//임시결과
int temp_result = 0;
//최종결과 - 각 자리 누르는 횟수 포함
int result = 0;
//현재 채널 번호
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

	//경우
	//1. 안누르는 경우
	if (target == 100) {
		cout << count_click;
		return 0;
	}
	//2. 숫자 누르는 경우
	for (int i = 0; i < 10; i++) {
	}

	//3. 추가 조작


	return 0;
}