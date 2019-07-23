#include <iostream>
#include <set>
using namespace std;

int get_length(int input) {


}

int swap(int i, int j) {

}



int tc;
int input_number_array[10];
int input_count_array[10];
set <int, int> is_visit;

int main() {

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> input_number_array[i];
		cin >> input_count_array[i];

		//교환횟수가 0일 때
		if (input_count_array[i] == 0) {
			cout << "#" << i + 1 << " " << input_number_array[i];
		}
		else {

		}
	}

	return 0;
}