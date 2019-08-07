#include <iostream>
#include <queue>

using namespace std;

int count_n;
priority_queue <int> pq;
int temp;

int main() {
	cin >> count_n;

	for (int i = 0; i < count_n; i++) {
		cin >> temp;
		if (temp != 0) {
			pq.push(temp);
		}
		else {
			
		}
	}


	return 0;
}