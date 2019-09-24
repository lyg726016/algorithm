#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int release_count = 0;
	int done_work_count = 0;

	while (done_work_count < progresses.size()) {
		queue <int> q;
		release_count = 0;

		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
			if (progresses[i] != -1) {
				q.push(progresses[i]);
			}
		}

		if (q.front() >= 100) {
			for (int i = 0; i < progresses.size(); i++) {
				if (progresses[i] >= 100) {
					release_count++;
					progresses[i] = -1;
					speeds[i] = 0;
					done_work_count++;
				}
			}
			if(release_count > 0)
			answer.push_back(release_count);
		}
	}

	return answer;
}

int main() {


	return 0;
}