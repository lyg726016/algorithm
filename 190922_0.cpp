#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int c_m;
int c_c;
int s_m = 0;
deque <int> dq;

//큐에 일 시킴

//다 끝난 큐 확인

//남은 작업확인

//작업중 1/ 쉬는 중 0
int is_q_running[11] = { 0, };
//작업 중 1/작업 끝 0 /작업 필요 2
int is_m_running[11] = { 2, };
//작업
int a_j[11];
//큐가 작업중인 메시지 인덱스번호
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
		//큐중에 노는 큐 확인
		for (int k = 0; k < c_c; k++){
			//노는 큐 있으면
			if (is_q_running[k] == 0){
				//남은 일중 처음일 시킴
				for (int j = 0; j < c_m; j++){
					//해야될 일 -> 진행중, 큐 진행중으로 변경
					if (is_m_running[j] == 2){
						//해당 일 진행 중으로 변경
						is_m_running[j] = 1;
						//해당 큐 일하는 중으로 변경
						is_q_running[k] = 1;
						//해당 큐가 처리하는 메시지 인덱스 저장
						q_i[k] = j;
						break;
					}
				}
			}
		}
		//진행 중인 큐 작업 진행
		for (int q = 0; q < c_c; q++){
			if (is_q_running[q] == 1){
				a_j[q_i[q]] = a_j[q_i[q]] - 1;
				//일 완료 시, 완료로 변경
				if (a_j[q_i[q]] <= 0){
					is_m_running[q_i[q]] = 0;
					//큐 다시 작업 
					is_q_running[q] = 0;
				}
			}
		}

		//작업 다 끝났나 확인
		bool is_all_done = true;
		for (int w = 0; w < c_m; w++){
			if (a_j[w] > 0){
				is_all_done = false;
			}
		}

		//다 끝날을 시 시간 출력
		if (is_all_done){
			cout << time;
			break;
		}
		time++;
	}
	return 0;
}