#include <iostream>
#include <queue>
#include <algorithm>

#define red 0
#define green 1
#define blue 2

using namespace std;

int map[1001] = { 0, };
int input_n;

//cost_red, cost_green..
int c_r[1001];
int c_g[1001];
int c_b[1001];


//현재 특정색(r,g,b)일 때의 최소값
int dp[1001][3];

//시작 집 , 각각 rgb 선택할 경우.
int result[1001][3];
int result_color[1001];

int sum;

int get_min(int input_a, int input_b){
	return input_a > input_b ? input_b : input_a;
}

void solve(){
	dp[0][red] = c_r[0];
	dp[0][green] = c_g[0];
	dp[0][blue] = c_b[0];

	for (int i = 1; i < input_n; i++){
		dp[i][red] = get_min(dp[i - 1][green] + c_r[i], dp[i - 1][blue] + c_r[i]);
		dp[i][green] = get_min(dp[i - 1][red] + c_g[i], dp[i - 1][blue] + c_g[i]);
		dp[i][blue] = get_min(dp[i - 1][green] + c_b[i], dp[i - 1][red] + c_b[i]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> input_n;

	for (int i = 0; i < input_n; i++){
		for (int j = 0; j < 3; j++){
			if (j == 0) cin >> c_r[i];
			if (j == 1) cin >> c_g[i];
			if (j == 2) cin >> c_b[i];
		}
	}

	solve();

	int result = 1000001;

	for (int i = 0; i < 3; i++){
		if (dp[input_n - 1][i] < result)
			result = dp[input_n - 1][i];
	}

	cout << result;

	return 0;
}