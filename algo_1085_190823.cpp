#include <iostream>
#include <algorithm>

using namespace std;

int input_x, input_y, input_w, input_h;

int main() {
	cin >> input_x >> input_y >> input_w >> input_h;

	int up_min = min(input_w - input_x, input_h - input_y);
	int down_min = min(input_x, input_y);
	cout << min(up_min, down_min);

	return 0;
}