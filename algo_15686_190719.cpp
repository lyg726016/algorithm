#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//배열 크기
int input_size;
//남은 치킨집 수
int min_count_store;
int map[51][51];

vector <pair<int, int>> location_house;
vector <pair<int, int>> location_store;
vector <bool> is_include;

vector <int> chicken_distance;

int count_store = 0;
int count_house = 0;

int final_result = 100001;

// 최소값 리턴
// input 두 수
// output 작은 수

int get_min(int x, int y) {
	return x < y ? x : y;
}

// 거리 구하는 함수
// input 집, 치킨
// output 거리 
int get_distance(int x_0, int y_0, int x_1, int y_1) {
	int temp = abs(x_0 - x_1) + abs(y_0 - y_1);
	return temp;
}

// 주어진 배열에 대해 치킨거리의 합 구하는 함수
// input 집배열, 치킨배열
// output이 해당 배열에서의 치킨거리의 합
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

//전체 치킨집 C m 을 생성하는 함수
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



// 치킨배열에서 m개를 선택했을 때의 최소 치킨거리 값 계산
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
			//집
			if (map[i][j] == 1) {
				location_house.push_back(make_pair(i, j));
				count_house++;
			}
			//치킨집
			else if (map[i][j] == 2) {
				location_store.push_back(make_pair(i, j));
				count_store++;
			}
			//나머지
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