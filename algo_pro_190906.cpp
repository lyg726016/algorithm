#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	pair <int, int> temp;

	for (int i = 0; i < computers.size(); i++) {
		queue<pair<int, int>> q;
		bool is_network = true;
		for (int j = 0; j < computers.size(); j++) {
			if (j != i) {
				if (computers[i][j] == 1) {
					q.push(make_pair(i, j));
					is_network = false;
				}
				//연결 -> 증가 x
				if (computers[i][j] == 2) {
					is_network = false;
				}
			}
		}
		//연결 x -> 증가
		if (is_network) {
			answer++;
		}

		while (q.size() != 0) {
			temp = q.front();
			computers[temp.second][temp.first] = 2;
			q.pop();

			for (int k = 0; k < computers.size(); k++) {
				if (temp.first != k) {
					if (computers[temp.second][k] == 1) {
						q.push(make_pair(temp.second, k));
						computers[temp.second][k] = 2;
					}
				}
			}
			if (q.size() == 0) {
				answer++;
			}
		}
		/*for (int q = 0; q < computers.size(); q++) {
		for (int w = 0; w < computers.size(); w++) {
		cout << computers[q][w];
		}
		cout << '\n';
		}
		cout << '\n';*/
	}
	return answer;
}