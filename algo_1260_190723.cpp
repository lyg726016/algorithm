#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack <int> s;
queue <int> q;

int s_visit[1001] = { 0, };
int q_visit[1001] = { 0, };

int q_temp;
int s_temp;

int rel[1001][1001] = { 0, };

int count_node, count_edge, start_node;
int input_a, input_b;

//dfs
void dfs(int start_node) {
	cout << start_node << " ";
	s_visit[start_node] = 1;

	for (int i = 1; i <= count_node; i++) {
		if (rel[start_node][i] == 1 && s_visit[i] == 0) {
			dfs(i);
		}
	}
}

int main() {

	cin >> count_node >> count_edge >> start_node;

	for (int i = 0; i < count_edge; i++)
	{
		cin >> input_a >> input_b;
		rel[input_a][input_b] = 1;
		rel[input_b][input_a] = 1;
	}

	dfs(start_node);
	cout << endl;


	q.push(start_node);
	q_visit[start_node] = 1;
	cout << start_node;

	//bfs
	while (!q.empty()) {
		q_temp = q.front();
		q.pop();

		for (int i = 1; i <= count_node; i++) {
			if (q_visit[i] != 1 && rel[q_temp][i] == 1) {
				q_visit[i] = 1;
				q.push(i);

				cout << " " << i;
			}
		}
	}

	return 0;
}