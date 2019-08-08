#include <iostream>
#include <queue>

using namespace std;

int input_n;
priority_queue <int> pq_f;
priority_queue <int> pq_s;
int temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		cin >> temp;
		pq_f.push(temp);
	}



	return 0;
}