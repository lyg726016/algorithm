#include <iostream>
#include <queue>

using namespace std;

int count_computer;
int count_node;

int rel[101][101];
int input_a, input_b;
int worm_computer[101] = { 0, 1, };
int result = 0;

queue <int> next_com;
int current_com;

int main() {
	cin >> count_computer >> count_node;

	for (int i = 0; i < count_node; i++) {
		cin >> input_a >> input_b;
		rel[input_a][input_b] = 1;
		rel[input_b][input_a] = 1;
	}

	next_com.push(1);

	while (!next_com.empty()) {
		//FIFO
		current_com = next_com.front();
		next_com.pop();

		for (int i = 2; i <= count_computer; i++) {
			if (rel[current_com][i] == 1 && worm_computer[i] != 1) {
				result++;
				worm_computer[i] = 1;
				next_com.push(i);
			}
		}
	}

	cout << result;
	return 0;
}