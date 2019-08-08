#include <iostream>
#include <queue>

using namespace std;

int input_n;
priority_queue <int> result_q;
int input_count;
int temp;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> input_count;

	for (int i = 0; i < input_count; i++) {
		cin >> temp;
		if (temp != 0) {
			result_q.push(temp);
		}
		else {
			if (result_q.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << result_q.top() << '\n';
				result_q.pop();
			}
		}
	}

	return 0;
}