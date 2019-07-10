#include <iostream>

//0~1011
#define MAX_Y 1011 + 1
#define MAX 1000000

using namespace std;

//테스트케이스
int t = 0;
//점프 횟수
int count_jump = 0;
//기본 계산 값
int base_count_jump = 0;
int base_distance = 0;
//각 점프별 거리
int *array_jump;
//최대 점프 거리
int max_jump = 0;
//각 거리별 값
int * result;
int current_x = 0;
// 점프 누적 거리
int * distance_jump;

//점프 누적 별 거리
void set_distance_jump() {
	distance_jump[0] = 0;
	for (int i = 1; i < MAX +1; i++) {
		distance_jump[i] = distance_jump[i - 1] + i;
	}
}

//get 거리별 최소 점프
int get_min_jump(int distance) {

	for (int i = 1; i < MAX; i++) {
		//점프 시작
		//남은 거리가 0이면 점프 중지
		if (current_x == distance) {
			return count_jump;
		}
		//이번 점프보다 남은 거리가 길면 점프
		if (distance >=  current_x + i) {
			current_x = current_x + i;
			count_jump++;
		}
		//이번 점프보다 남은 거리가 짧으면 점프 초기화 후 첨프
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
	//각 거리에 대한 점프횟수 임시 저장용
	cin >> t;

	//출력
	result = (int *)malloc(sizeof(int) * t);
	for (int i = 0; i < t; i++) {
		//var initializing
		count_jump = 0;
		start_x = 0;

		cin >> start_x >> end_y;

		//10의 5승 ~ 10의 6승 => 10의 5승 빼고 시작.
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