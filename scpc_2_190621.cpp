#include <iostream>
#include <cstring>
#include <math.h>

//scpc_2��


#pragma warning(disable:4996)

#define MAX_BOX 1000
#define PIE 3.141592653589793238

using namespace std;

double r = 0;
double T = 0;
//�� ���� ��ġ 1�̻� 1000����
double r_start = 0 +1;
//�� ���� ��ġ 1�̻� �鸸 ����
double r_end = 0;

//���� ���� x, y��ǥ
//r_x�� 1���� ����, r_y�� r�� ����
double r_x = 0 +1;
double r_y = 0;

//box�� ���� x,y ��ǥ
double box_left_x = 0 +1;
double box_left_y = 0 +1;

double box_right_x = 0;
double box_right_y = 0;

//box ����
double count_box = 0;

//bot�� ��ǥ
double box_left[MAX_BOX];
double box_right[MAX_BOX];
double box_height[MAX_BOX];

//result ���� ���
double total = 0.0;


//������ ������
double rad2deg(double radian)
{
	return radian * 180 / PIE;
}

//���������� ���� ������ �簢���� ������ ��
//Z�� ���ϴ� �Լ�


//(r-z) * 2�� ���ؾߴ�
double get_z(double input_box_height) {
	double z_2 = input_box_height * (2 * r - input_box_height);
	double z = pow(z_2, 0.5);

	return z;
}

//���ζ����� ���ϴ� �Լ�
double get_radian(double input_z) {
	double radian = sin(input_z / r);
	return radian;
}

//���̰� ���������� ���� �� ȣ�� ����
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

//�̵��Ÿ� ��� �� r-z��ŭ x����� �� �̵�
//+ get_row_ho * 2�� ����

//group 1
//ȣ�� �����ϰ� ��� �̵��Ÿ�(������ �̵� ���ϰ� �������� �̵� ��)
//ȣ�� �� ������ x �̵��Ÿ�
double get_move_x() {
	//��ֹ��� ���� ���� (r x 2) ��ŭ �̵� ����
	double origin_move_x = r_end - r_start;
	double move_x = origin_move_x - (count_box * r * 2);
	return move_x;
}

//ȣ�� �� ������ y �̵��Ÿ�
double get_move_y() {
	//���ǹ��� �������� (r x 2) ��ŭ �̵� ����
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

//ȣ�� �׸� ���� �̵��Ÿ�
double get_move_ho(double input_count_box) {
	//�� �ѷ� ���� 2 * PIE * R
	double origin_ho = 2 * PIE * r;

	//��ֹ� �ϳ��� 90�� ȣ 2�� = ���� ȣ�� 1/2
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

	//�׽�Ʈ ���̽� ����
	cin >> T;

	//�׽�Ʈ ����
	for (double t = 0; t < T; t++) {

		//���� ������
		cin >> r;

		//���� �����
		cin >> r_start;

		//���� ������
		cin >> r_end;

		//��ֹ��� ����
		cin >> count_box;

		//��ֹ��� ������ǥ, ������ ��ǥ, ����
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

		//total move �� (
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