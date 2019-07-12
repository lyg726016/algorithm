#include <iostream>

using namespace std;

int n = 0;
int k = 0;

long long C[1001][1001];

int main() {

	cin >> n >> k;

	C[0][0] = 1;

	for (int i = 1; i < 1001; i++) {
		C[i][0] = 1;
		C[i][i] = 1;

		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007 ;
		}
		
	}

	cout << C[n][k];

	return 0;
}