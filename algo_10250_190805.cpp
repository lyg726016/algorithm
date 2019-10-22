#include <iostream>

using namespace std;

int tc;
int input_cmd;
int input_gh;
int input_n;

int result_cmd;
int result_gh;

int gh_max[100];

int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> input_cmd >> input_gh >> input_n;


		for (int i = 1; i < 100; i++) {
			gh_max[i] = input_cmd * i;
			if (input_n <= gh_max[i]) {
				result_gh = i;
				break;
			}
		}

		result_cmd = input_n % input_cmd;

		if (result_cmd == 0) {
			result_cmd = input_cmd;
		}

		if (result_gh < 10) {
			cout << result_cmd << "0" << result_gh << '\n';
		}
		else {
			cout << result_cmd << result_gh << '\n';
		}
	}

	return 0;
}