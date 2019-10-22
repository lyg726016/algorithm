#include <iostream>
#include <queue>

using namespace std;

int tc;
int input_n;
int input_m;
int min_v = 10001;
int map[1001][1001] = { 0, };

bool check(int * visit){
	for (int i = 1; i <= input_n; i++){
		if (visit[i] != 1){
			return false;
		}
	}
	return true;
}

void solve(queue<int> q, int * visit, int r_v){
	//다 돌았으면 값 갱신 후 종료
	if (check(visit)){
		if (min_v > r_v){
			min_v = r_v;
			return;
		}
		//else - do nothing
	}
	//현재 최소보다 크면 종료
	if (r_v > min_v){
		return;
	}

	if (r_v >= input_m){
		return;
	}

	queue<int> n_q;
	while (!q.empty()){
		int temp = q.front();
		q.pop();

		for (int i = 1; i <= input_n; i++){
			if (map[temp][i] == 1){
				n_q.push(i);
				visit[i] = 1;
				solve(n_q, visit, r_v + 1);
			}
		}
	}

	if (n_q.empty()){
		return;
	}
}

int main(){
	cin >> tc;

	for (int i = 0; i < tc; i++){
		cin >> input_n >> input_m;

		min_v = 10001;

		for (int j = 0; j < input_m; j++){
			int temp_a, temp_b;
			cin >> temp_a >> temp_b;
			map[temp_a][temp_b] = 1;
			map[temp_b][temp_b] = 1;
		}
		int visit[1001] = { 0, };

		for (int j = 1; j <= input_n; j++){
			visit[j] = 1;
			queue <int> q;
			q.push(j);
			solve(q, visit, 0);
		}
		cout << min_v << '\n';
	}
	return 0;
}