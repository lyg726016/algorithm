#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_COMP	100

bool network[MAX_COMP + 1][MAX_COMP + 1] = { false, };
bool visited[MAX_COMP + 1] = { false, };
int cntComputer;
int cntVirus = 0;
queue<int> Q;

void virus() {

	while (!Q.empty()) {
		int num = Q.front();
		Q.pop();
		for (int i = 1; i <= cntComputer; i++) {
			if (network[num][i] && !visited[i]) {
				cntVirus++;
				visited[i] = true;
				Q.push(i);
			}
		}
	}
}

int main() {

	scanf("%d", &cntComputer);

	int cntPair;

	scanf("%d", &cntPair);

	for (int i = 0; i < cntPair; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		network[a][b] = true;
		network[b][a] = true;
	}

	visited[1] = true;
	Q.push(1);
	virus();

	printf("%d", cntVirus);


	return 0;
}