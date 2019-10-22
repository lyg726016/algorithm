#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int land[12][12];
vector<int> tree[12][12];
int summer[12][12];
int winter[12][12];

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	// 놀랍게도 양분은 모든 칸이 5만큼 들어있었다.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			land[i][j] = 5;
			scanf("%d", &winter[i][j]);
		}

	// r과 c는 1부터 시작한다.
	for (int i = 0; i < m; i++) {
		int y, x, age;
		scanf("%d %d %d", &y, &x, &age);
		y--, x--;
		tree[y][x].push_back(age);
	}

	while (k--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!tree[i][j].empty()) {
					// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
					sort(tree[i][j].begin(), tree[i][j].end());
					for (int t = 0; t < tree[i][j].size(); t++) {
						int cur = tree[i][j][t];

						// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
						// 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다.
						if (cur <= land[i][j]) {
							land[i][j] -= cur;
							tree[i][j][t]++;
						}
						// 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 
						// 양분을 먹지 못하고 즉시 죽는다.
						// 봄에 죽은 나무가 양분으로 변하게 된다. 
						// 소수점 아래는 버린다.
						else {
							tree[i][j].erase(tree[i][j].begin() + t);
							summer[i][j] += (cur / 2);
							t--;
						}
					}
				}
			}
		}

		// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				land[i][j] += summer[i][j];

		memset(summer, 0, sizeof(summer));

		vector<int> tmpTree[12][12];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int t = 0; t < tree[i][j].size(); t++) {
					tmpTree[i][j].push_back(tree[i][j][t]);
				}

		// 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 
		// 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				for (int t = 0; t < tree[i][j].size(); t++) {
					if (tree[i][j][t] % 5)
						continue;

					for (int q = 0; q < 8; q++) {
						int ny = dy[q] + i;
						int nx = dx[q] + j;

						if ((0 <= ny && ny < n) && (0 <= nx && nx < n))
							tmpTree[ny][nx].push_back(1);
					}
				}
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				tree[i][j].clear();
				for (int t = 0; t < tmpTree[i][j].size(); t++)
					tree[i][j].push_back(tmpTree[i][j][t]);
			}

		// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 
		// 각 칸에 추가되는 양분의 양은 A[r][c]
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				land[i][j] += winter[i][j];
	}

	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += tree[i][j].size();

	printf("%d\n", ans);
	return 0;
}