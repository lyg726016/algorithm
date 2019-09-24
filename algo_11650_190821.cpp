#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input_n;
int temp_x, temp_y;
vector<pair <int, int>> v;

bool get_big(pair <int, int> first, pair <int, int> second) {
	if (first.first < second.first) {
		return true;
	}
	else if (first.first == second.first) {
		if (first.second < second.second) {
			return true;
		}
		else
		{
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	cin >> input_n;

	for (int i = 0; i < input_n; i++) {
		cin >> temp_x >> temp_y;
		v.push_back(make_pair(temp_x, temp_y));
	}

	sort(v.begin(), v.end(), get_big);


	for (int i = 0; i < input_n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}