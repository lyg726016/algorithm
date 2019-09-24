#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int a, b;

		cin >> a >> b;
		int aa = a;

		for (int j = 0; j < b -1; j++) {
			aa = (aa * a) % 10;
			aa = aa % 10;
		}
		if (aa == 0) {
			cout << 10 << '\n';
		}
		else {
			cout << aa << '\n';
		}
	}


	return 0;
}