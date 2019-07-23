#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//�迭 ũ��
int input_size;
//���� ġŲ�� ��
int min_count_store;
int map[51][51];

vector <pair<int, int>> location_house;
vector <pair<int, int>> location_store;
vector <bool> is_include;

vector <int> chicken_distance;

int count_store = 0;
int count_house = 0;

int final_result = 100001;

// �ּҰ� ����
// input �� ��
// output ���� ��

int get_min(int x, int y) {
	return x < y ? x : y;
}

// �Ÿ� ���ϴ� �Լ�
// input ��, ġŲ
// output �Ÿ� 
int get_distance(int x_0, int y_0, int x_1, int y_1) {
	int temp = abs(x_0 - x_1) + abs(y_0 - y_1);
	return temp;
}

// �־��� �迭�� ���� ġŲ�Ÿ��� �� ���ϴ� �Լ�
// input ���迭, ġŲ�迭
// output�� �ش� �迭������ ġŲ�Ÿ��� ��
int get_chicken_distance() {
	int temp;
	int min = 10001;
	int result = 0;
	for (int i = 0; i < count_house; i++) {
		min = 10001;
		for (int j = 0; j < count_store; j++) {
			if (is_include.at(i) == true) {
				temp = get_distance(location_house.at(i).first, location_house.at(i).second, location_store.at(i).first, location_store.at(i).second);
				min = get_min(temp, min);
			}
		}
		result += min;
	}
	return result;
}

//��ü ġŲ�� C m �� �����ϴ� �Լ�
bool change_bool() {
	bool is_done = false;


	return is_done;
}

void combination(int* arr, int index, int n, int r, int target) {
	if (r == 0) 
		cout << arr << index;
	else if (target == n) return;
	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}//end combination()



// ġŲ�迭���� m���� �������� ���� �ּ� ġŲ�Ÿ� �� ���
// input 
// output x
void get_result() {
	while (true) {



		if (change_bool()) {
			break;
		}
	}
	final_result = 5;
}

int main() {

	cin >> input_size >> min_count_store;


	for (int i = 0; i < input_size; i++) {
		for (int j = 0; j < input_size; j++) {
			cin >> map[i][j];
			//��
			if (map[i][j] == 1) {
				location_house.push_back(make_pair(i, j));
				count_house++;
			}
			//ġŲ��
			else if (map[i][j] == 2) {
				location_store.push_back(make_pair(i, j));
				count_store++;
			}
			//������
			else {

			}
		}
	}

	for (int i = 0; i < count_store; i++) {
		is_include.push_back(false);
	}

	get_result();

	cout << final_result;


	return 0;
}