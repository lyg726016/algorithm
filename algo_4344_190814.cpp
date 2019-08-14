#include <iostream>

using namespace std;

int tc;
int count_n;
int arr_input[1001];
int sum = 0;
double avg_v = 0.0;
int count_v = 0;
double result_v = 0.0;


int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> count_n;
		count_v = 0;
		sum = 0;
		for (int j = 0; j < count_n; j++) {
			cin >> arr_input[j];
			sum += arr_input[j];
		}

		avg_v = (double)sum / count_n;

		for (int k = 0; k < count_n; k++) {
			if (arr_input[k] > avg_v) {
				count_v++;
			}
		}
		result_v = (double)count_v / count_n;
		result_v = result_v * 100;
		printf("%0.3f", result_v);
		cout << "%" << '\n';
	}

	return 0;
}