#include <iostream>

using namespace std;

long long dp[100001] = { -1000, };

long long get_m(long long x, long long y){
	return x > y ? x : y;
}

int main(){

	long long input_l;
	long long temp;

	cin >> input_l;
	cin >> temp;
	dp[0] = temp;
	long long result = dp[0];

	for (int i = 1; i < input_l; i++){
		cin >> temp;
		dp[i] = get_m(temp, dp[i - 1] + temp);
		result = get_m(result, dp[i]);
	}

	cout << result;
	return 0;
}