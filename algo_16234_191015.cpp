#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;

int N, L, R;
int nation[51][51];
int unionNation[51][51];
bool visit[51][51];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int nationCnt = 0;
int peopleCnt = 0;

void dfs(int r, int c, int n){
	unionNation[r][c] = n;
	visit[r][c] = true;
	peopleCnt += nation[r][c];
	nationCnt++;
	for (int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
		if (visit[nr][nc]) continue;
		int diff = abs(nation[r][c] - nation[nr][nc]);
		if (diff >= L && diff <= R){
			dfs(nr, nc, n);
		}
	}
}

int main(){
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> nation[i][j];
		}
	}
	int time = 0;
	while (true){
		memset(visit, false, sizeof(visit));
		int UnionCnt = 0;
		map<int, int> movingPeople;
		//연합국 수와 해당 연합국 인구수 계산
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (visit[i][j]) continue;
				peopleCnt = 0;
				nationCnt = 0;
				dfs(i, j, UnionCnt);
				movingPeople[UnionCnt] = peopleCnt / nationCnt;
				UnionCnt++;
			}
		}
		//모든 국가가 연합을 이루지 않을때 종료
		if (UnionCnt == N*N) break;
		//인구수 이동
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				nation[i][j] = movingPeople[unionNation[i][j]];
			}
		}
		time++;
	}
	cout << time << endl;
	return 0;
}