#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;


int current_count = 1;
int target_count;
string input_s;
vector<int> v_i;
deque<int> q;
int is_in[11] = { 0, };

void bfs(int current_size, int target_size, deque<int> l_q){
	if (current_size > target_size)
		return;
	if (current_size == target_size){
		if (current_count == target_count){
			for (int i = 0; i < l_q.size(); i++){
				cout << l_q.front();
				l_q.pop_front();
			}
			return;
		}
		current_count++;
	}

	for (int i = 0; i < v_i.size(); i++){
		if (is_in[i] == 0){
			l_q.push_back(v_i[i]);
			is_in[i] = 1;
			bfs(current_size + 1, target_size, l_q);
			is_in[i] = 0;
			l_q.pop_back();
		}
	}

}
int main(void) {
	getline(cin, input_s);
	cin >> target_count;
	for (int i = 0; i < input_s.length(); i++){
		if (i % 2 == 0){
			char temp = input_s[i];
			v_i.push_back(temp - '0');
		}
	}
	sort(v_i.begin(), v_i.end());
	/*for (int i = 0; i < v_i.size(); i++){
	q.push_back(v_i[i]);
	}*/
	deque<int> e_q;
	bfs(0, v_i.size(), e_q);

	//1 0 2
	//오름차순
	//0 1 2
	//0 2 1
	//1 0 2
	//1 2 0
	//2 0 1
	//2 1 0


	return 0;
}