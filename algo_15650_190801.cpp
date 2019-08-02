#include <iostream>

using namespace std;

int n, m;
int *arr;
bool *isused;

void func(int* arr, int k, int current_number) { // ���� k������ ���� ������.

	if (k == m) { // m���� ��� ��������
		for (int i = 0; i < m; i++)
			cout << arr[i] + 1 << ' '; // arr�� ����ص� ���� ���.(0���� m-1������ �ƴ϶� 1���� m�����̹Ƿ� +1�� ����)

		cout << '\n';

		return;
	}

	for (int i = current_number; i < n; i++) { // 1���� n������ ���� ����
		if (!isused[i]) { // ���� i�� ������ �ʾ�����
			arr[k] = i; // k��° ���� i�� ����
			isused[i] = 1; // i�� ���Ǿ��ٰ� ǥ��
			func(arr, k + 1, i); // ���� ���� ���Ϸ� �� �ܰ� �� ��
			isused[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i�� ���� ������ �ʾҴٰ� �����.
		}
	}
}

int main(void) {

	cin >> n >> m;
	arr = new int[m];
	isused = new bool[n];

	for (int i = 0; i < n; i++)
		isused[i] = 0;

	func(arr, 0, 0);

	return 0;
}