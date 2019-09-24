#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int input_n;
int temp_x, temp_y;



priority_queue <pair <int, int>, vector<pair<int, int >>, greater<pair<int, int>>> pq;


int main() {
	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		cin >> temp_x >> temp_y;
		pq.push(make_pair(temp_y, temp_x));
	}

	for (int i = 0; i < input_n; i++) {
		cout << pq.top().second  << " " << pq.top().first << '\n';
		pq.pop();
	}

	return 0;
}