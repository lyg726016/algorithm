#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int tc;
int count_file;
int f_s[501];
int result = 0;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> tc;
	for (int i = 0; i < tc; i++){
		cin >> count_file;
		priority_queue <int, vector<int>, greater<int>> pq;
		result = 0;
		for (int j = 0; j < count_file; j++){
			cin >> f_s[j];
			pq.push(f_s[i]);
		}

		//시작 -> 개수 -1
		//30 + 30
		result += pq.top();
		pq.pop();

		result += pq.top();
		pq.pop();

		//insert 60
		pq.push(result);

		int temp;

		for (int i = 0; i < count_file -1; i++){
			//40
			temp = pq.top();
			pq.pop();
			//50
			temp += pq.top();
			pq.pop();

			result += temp;
			pq.push(temp);
		}

		cout << result << '\n';
	}
	return 0;
}