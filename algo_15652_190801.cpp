#include <iostream>

using namespace std;

int n, m;
int *arr;
bool *isused;

void func(int* arr, int k) { // ���� k������ ���� ������.

	if (k == m) { // m���� ��� ��������
		for (int i = 0; i < m; i++)
			cout << arr[i] + 1 << ' '; // arr�� ����ص� ���� ���.(0���� m-1������ �ƴ϶� 1���� m�����̹Ƿ� +1�� ����)

		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++) { // 1���� n������ ���� ����
		arr[k] = i; // k��° ���� i�� ����

		if (k == 0) {
			func(arr, k + 1); // ���� ���� ���Ϸ� �� �ܰ� �� ��
		}
		else {
			if (arr[k - 1] <= arr[k]) {
				func(arr, k + 1); // ���� ���� ���Ϸ� �� �ܰ� �� ��
			}
			else {
				//��ŵ
				continue;
			}
		}
	}
}

int main(void) {

	cin >> n >> m;
	arr = new int[m];
	isused = new bool[n];

	for (int i = 0; i < n; i++)
		isused[i] = 0;

	func(arr, 0);

	return 0;
}