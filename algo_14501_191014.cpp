#include <iostream>
#include <algorithm>
using namespace std;

int t[16];
int p[16];
int d[16 + 5];
int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++){
		cin >> t[i] >> p[i];
		d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
		d[i + 1] = max(d[i], d[i + 1]);
	}
	cout << d[tc];
	return 0;
}