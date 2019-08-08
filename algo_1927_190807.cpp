#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int input_count;
priority_queue <int, vector<int>, greater<int> > pq;
int temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> input_count;

	for (int i = 0; i < input_count; i++)
	{
		cin >> temp;
		if (temp == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}

	return 0;
}