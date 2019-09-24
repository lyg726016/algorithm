#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(int n) {
	string answer = "";
	int current_n;
	int current_m;
	int left_n;

	while (true) {
		if (n == 0) {
			return answer;
		}
		for (int i = 0; i < 40; i++) {
			if (n < pow(3, i)) {
				current_n = i - 1;
				break;
			}
		}
		for (int i = 1; i < 4; i++) {
			if (n < i * pow(3, current_n)) {
				current_m = i - 1;
				break;
			}
		}

		if (n == current_m * pow(3, current_n)) {
			current_n -= 1;
			for (int i = 1; i < 4; i++) {
				if (n < i * pow(3, current_n)) {
					current_m = i - 1;
					break;
				}
			}
			if (current_m == 1) {
				answer += "1";
			}
			else if (current_m == 2) {
				answer += "2";
			}
			else {
				answer += "4";
			}
		}
		else {

			if (current_m == 1) {
				answer += "1";
			}
			else if (current_m == 2) {
				answer += "2";
			}
			else {
				answer += "4";
			}
		}
		n -= current_m * pow(3, current_n);
	}
}

int main() {

	solution(3);

	return 0;
}