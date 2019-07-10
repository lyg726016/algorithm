#include <iostream>

//https://www.acmicpc.net/problem/2749
//피사노주기 - 피보나치 수열에서 10의 n승까지 구할 때 15*(10 n-1승) 

using namespace std;

long long a[1500001];
int INF = 1000000;


void fibonacci() {
	a[0] = 0;
	a[1] = 1;

	//피사노주기 - 피보나치 수열에서 10의 n승까지 구할 때 15*(10 n-1승) 
	for (int i = 0; i < 1500000; i++) {
		a[i + 2] = (a[i + 1] + a[i]) % INF;
	}
}

int main() {
	long long n;
	cin >> n;
	fibonacci();
	cout << a[n % 1500000] << "\n";

	return 0;

}
