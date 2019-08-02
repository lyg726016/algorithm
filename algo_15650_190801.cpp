#include <iostream>

using namespace std;

int n, m;
int *arr;
bool *isused;

void func(int* arr, int k, int current_number) { // 현재 k개까지 수를 택했음.

	if (k == m) { // m개를 모두 택했으면
		for (int i = 0; i < m; i++)
			cout << arr[i] + 1 << ' '; // arr에 기록해둔 수를 출력.(0부터 m-1까지가 아니라 1부터 m까지이므로 +1을 해줌)

		cout << '\n';

		return;
	}

	for (int i = current_number; i < n; i++) { // 1부터 n까지의 수에 대해
		if (!isused[i]) { // 아직 i가 사용되지 않았으면
			arr[k] = i; // k번째 수를 i로 정함
			isused[i] = 1; // i를 사용되었다고 표시
			func(arr, k + 1, i); // 다음 수를 정하러 한 단계 더 들어감
			isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 명시함.
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