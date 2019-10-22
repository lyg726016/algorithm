#include <iostream>
#include <cstring>

using namespace std;

int n, l;
int map[101][101];
int result = 0;

//���� �����鼭 Ȯ��
int temp[101] = { 0, };


//����� ��
//�������� ���
//1 �������� ���

//1 �ʰ� �������� ���
//����
int more_than_one_x(int y){
	for (int i = 0; i < n - 1; i++){
		if (abs(map[y][i + 1] - map[y][i]) > 1){
			return 1;
		}
	}
	return 0;
}

int make_wall_x(int y){
	int dif;
	for (int i = 0; i < n - 1; i++){
		if (dif = map[y][i + 1] - map[y][i]){
			//�������� ���
			if (dif > 0){
				int c_v = map[y][i];
				//���� ���� �� ���� ��� ����
				if (i - (l - 1) < 0){
					return 0;
				}
				//���� �־�
				for (int j = 0; j < l; j++){
					//�������� ���� ��� ����
					if (map[y][i - j] != c_v){
						return 0;
					}
					temp[i - j]++;
				}
			}
			//�������� ���
			if (dif < 0){
				int c_v = map[y][i + 1];
				//���� ���� �� ���� ��� ����
				if (i + 1 + (l - 1) > n - 1){
					return 0;
				}
				//���� �־�
				for (int j = 0; j < l; j++){
					//�������� ���� ��� ����
					if (map[y][i + 1 + j] != c_v){
						return 0;
					}
					temp[i + 1 + j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (temp[i] > 1){
			return 0;
		}
	}
	return 1;
}

//����
int more_than_one_y(int x){
	for (int i = 0; i < n - 1; i++){
		if (abs(map[i + 1][x] - map[i][x]) > 1){
			return 1;
		}
	}
	return 0;
}

int make_wall_y(int x){
	int dif;
	for (int i = 0; i < n - 1; i++){
		if (dif = map[i + 1][x] - map[i][x]){
			//�������� ���
			if (dif > 0){
				int c_v = map[i][x];
				//���� ���� �� ���� ��� ����
				if (i - (l - 1) < 0){
					return 0;
				}
				//���� �־�
				for (int j = 0; j < l; j++){
					//�������� ���� ��� ����
					if (map[i - j][x] != c_v){
						return 0;
					}
					temp[i - j]++;
				}
			}
			//�������� ���
			if (dif < 0){
				int c_v = map[i + 1][x];
				//���� ���� �� ���� ��� ����
				if (i + 1 + (l - 1) > n - 1){
					return 0;
				}
				//���� �־�
				for (int j = 0; j < l; j++){
					//�������� ���� ��� ����
					if (map[i + 1 + j][x] != c_v){
						return 0;
					}
					temp[i + 1 + j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (temp[i] > 1){
			return 0;
		}
	}
	return 1;
}

//�������� ���
//1 �������� ���

//1 �̸� �������� ���
int main(){
	cin >> n >> l;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++){
		//���� �˻�
		//���� ���� 1 �ʰ�
		if (more_than_one_x(i)){
			continue;
		}
		//���� ���ƾ� �ϴ� ���� ���� ����
		memset(temp, 0, sizeof(temp));
		if (make_wall_x(i)){
			result++;
		}
		else{
			//���� �� �����
			continue;
		}
	}

	for (int i = 0; i < n; i++){
		//���� �˻�
		if (more_than_one_y(i)){
			continue;
		}
		//���� ���ƾ� �ϴ� ���� ���� ����
		memset(temp, 0, sizeof(temp));
		if (make_wall_y(i)){
			result++;
		}
		else{
			//���� �� �����
			continue;
		}

	}
	cout << result;
	return 0;
}