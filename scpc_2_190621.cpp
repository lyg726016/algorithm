#include <iostream>
#include <cstring>
#include <math.h>

//scpc_2번


#pragma warning(disable:4996)

#define MAX_BOX 1000
#define PIE 3.141592653589793238

using namespace std;

double r = 0;
double T = 0;
//원 시작 위치 1이상 1000이하
double r_start = 0 +1;
//원 종료 위치 1이상 백만 이하
double r_end = 0;

//원의 현재 x, y좌표
//r_x는 1부터 시작, r_y는 r로 시작
double r_x = 0 +1;
double r_y = 0;

//box의 좌측 x,y 좌표
double box_left_x = 0 +1;
double box_left_y = 0 +1;

double box_right_x = 0;
double box_right_y = 0;

//box 개수
double count_box = 0;

//bot의 좌표
double box_left[MAX_BOX];
double box_right[MAX_BOX];
double box_height[MAX_BOX];

//result 최종 결과
double total = 0.0;


//라디안을 각도로
double rad2deg(double radian)
{
	return radian * 180 / PIE;
}

//반지름보다 작은 높이인 사각형을 만났을 때
//Z를 구하는 함수


//(r-z) * 2를 더해야댐
double get_z(double input_box_height) {
	double z_2 = input_box_height * (2 * r - input_box_height);
	double z = pow(z_2, 0.5);

	return z;
}

//사인라디안을 구하는 함수
double get_radian(double input_z) {
	double radian = sin(input_z / r);
	return radian;
}

//높이가 반지름보다 작을 때 호의 길이
double get_row_ho(double input_box_height) {
	double output_z = get_z(input_box_height);
	double output_raidan = get_radian(output_z);
	//double angle = rad2deg(output_raidan);
	double angle = rad2deg(atan2(output_z, r - input_box_height));
	//double temp_angle = 90 - angle;

	double origin_ho = 2 * PIE * r;

	double result = (angle / 360) * origin_ho * 2;

	return result;
}

//이동거리 계산 시 r-z만큼 x축따라서 더 이동
//+ get_row_ho * 2를 하자

//group 1
//호를 제외하고 모든 이동거리(원으로 이동 안하고 직선으로 이동 시)
//호를 뺀 나머지 x 이동거리
double get_move_x() {
	//장애물의 개수 마다 (r x 2) 만큼 이동 덜함
	double origin_move_x = r_end - r_start;
	double move_x = origin_move_x - (count_box * r * 2);
	return move_x;
}

//호를 뺀 나머지 y 이동거리
double get_move_y() {
	//장의물의 개수마다 (r x 2) 만큼 이동 덜함
	double temp = 0;
	double origin_move_y = 0;
	double move_y = 0;
	for (int i = 0; i < count_box; i++) {
		if (box_height[i] >= r) {
			origin_move_y += (box_height[i]-r)*2;
			temp++;
		}
	}
	//origin_move_y *= 2;
	//move_y = origin_move_y - (temp * r * 2);
	return origin_move_y;
}

//호를 그릴 떄의 이동거리
double get_move_ho(double input_count_box) {
	//원 둘래 공식 2 * PIE * R
	double origin_ho = 2 * PIE * r;

	//장애물 하나당 90도 호 2번 = 원래 호의 1/2
	double move_ho = input_count_box * origin_ho / 2;
	return move_ho;
}

//group 2
double sub_move_ho() {
	return 0.0;
}



int main()
{

	freopen("input.txt", "r", stdin);

	//테스트 케이스 개수
	cin >> T;

	//테스트 시작
	for (double t = 0; t < T; t++) {

		//원의 반지름
		cin >> r;

		//공의 출발점
		cin >> r_start;

		//공의 도착점
		cin >> r_end;

		//장애물의 개수
		cin >> count_box;

		//장애물의 왼쪽좌표, 오른쪽 좌표, 높이
		for (int i = 0; i < count_box; i++) {
			cin >> box_left[i];
			cin >> box_right[i];
			cin >> box_height[i];
		}

		bool condition_group_1 = true;

		for (int i = 0; i < count_box; i++) {
			if (r > box_height[i]) {
				condition_group_1 = false;
				break;
			}
		}

		//total move 값 (
		double total = 0.0;

		//group 1
		if (condition_group_1) {
			double move_x = get_move_x();
			double move_y = get_move_y();
			double move_ho = get_move_ho(count_box);

			total = move_x + move_y + move_ho;
			printf("Case #");
			printf("%d\n", t + 1);
			printf("%.20f\n", total);
		}


		//group 2
		else {
			double move_x = get_move_x();
			double move_y = get_move_y();
			double total_ho = 0.0;
			double temp_count_box = 0;

			for (int i = 0; i < count_box; i++) {
				if (box_height[i] < r) {
					double temp_ho = get_row_ho(box_height[i]);
					total_ho += temp_ho;
					double temp_z = get_z(box_height[i]);
					move_x += (r - temp_z) * 2;
				}
				else {
					temp_count_box++;
				}
			}
			total_ho += get_move_ho(temp_count_box);
			total = move_x + move_y + total_ho;
			printf("Case #");
			printf("%d\n", t + 1);
			//printf("%.20f\n", total);
			printf("%.20lf\n", total);
		}
	}

	return 0;
}