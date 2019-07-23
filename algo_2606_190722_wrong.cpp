#include <iostream>
#include <vector>

using namespace std;

int count_computer;
int count_node;

int com[101][101] = { 0, };
int worm_com[101] = { 0, 1, 0};

int input_a, input_b;
int result = 0;


int main() {
	
	cin >> count_computer;
	cin >> count_node;

	for (int i = 0; i < count_node; i++) {
		cin >> input_a >> input_b;
		com[input_a][input_b] = 1;
		com[input_b][input_a] = 1;
	}

	for (int i = 1; i <= count_computer; i++) {
		for (int j = 1; j <= count_computer; j++) {
			if ((com[i][j] == 1 || com[j][i] == 1) && (worm_com[i] == 1 || worm_com[j] == 1)) {
				worm_com[j] = 1;
				worm_com[i] = 1;
			}
		}
	}


	cout << result << endl;
	return 0;
}