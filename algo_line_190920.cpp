#include <queue>
#include <iostream>

using namespace std;

//https://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/

int solve(int conyPosition, int brownPosition) {
	int time = 0;
	bool visit[200001][2];
	queue<pair<int, int> > queue;
	memset(visit, 0, sizeof(visit));
	queue.push(make_pair(brownPosition, 0));
	while (1) {
		conyPosition += time;
		if (conyPosition > 200000)
			return -1;
		if (visit[conyPosition][time % 2])
			return time;
		for (int i = 0, size = queue.size(); i < size; i++) {
			int currentPosition = queue.front().first;
			int newTime = (queue.front().second + 1) % 2;
			int newPosition;
			queue.pop();
			newPosition = currentPosition - 1;
			if (newPosition >= 0 && !visit[newPosition][newTime]) {
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}
			newPosition = currentPosition + 1;
			if (newPosition < 200001 && !visit[newPosition][newTime]) {
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}
			newPosition = currentPosition * 2;
			if (newPosition < 200001 && !visit[newPosition][newTime]) {
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}
		}
		time++;
	}
}

int main(){


	return 0;
}