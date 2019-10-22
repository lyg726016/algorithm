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

	// ����Ե� ����� ��� ĭ�� 5��ŭ ����־���.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			land[i][j] = 5;
			scanf("%d", &winter[i][j]);
		}

	// r�� c�� 1���� �����Ѵ�.
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
					// �ϳ��� ĭ�� ���� ���� ������ �ִٸ�, ���̰� � �������� ����� �Դ´�.
					sort(tree[i][j].begin(), tree[i][j].end());
					for (int t = 0; t < tree[i][j].size(); t++) {
						int cur = tree[i][j][t];

						// ������ ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�. 
						// ������ ������ ������ �ִ� 1��1 ũ���� ĭ�� �ִ� ��и� ���� �� �ִ�.
						if (cur <= land[i][j]) {
							land[i][j] -= cur;
							tree[i][j][t]++;
						}
						// ����, ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ 
						// ����� ���� ���ϰ� ��� �״´�.
						// ���� ���� ������ ������� ���ϰ� �ȴ�. 
						// �Ҽ��� �Ʒ��� ������.
						else {
							tree[i][j].erase(tree[i][j].begin() + t);
							summer[i][j] += (cur / 2);
							t--;
						}
					}
				}
			}
		}

		// ������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. 
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

		// �������� ������ �����Ѵ�. �����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�, 
		// ������ 8���� ĭ�� ���̰� 1�� ������ �����. 
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

		// �ܿ￡�� S2D2�� ���� ���ƴٴϸ鼭 ���� ����� �߰��Ѵ�. 
		// �� ĭ�� �߰��Ǵ� ����� ���� A[r][c]
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				land[i][j] += winter[i][j];
	}

	// K���� ���� �� ���� ���� ����ִ� ������ ����
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += tree[i][j].size();

	printf("%d\n", ans);
	return 0;
}