#include <iostream>

using namespace std;

#define MAX 106 + 1
#define MIN 1
#define TEST_MAX 10000 + 1

int array_count[MAX];
bool array_is_counted[MAX];
int t = 0;


int next_step(int input) {
	if (input == 1)
		return 1;
	if (input % 2 == 0) {
		return (input / 2);
	}
	else {
		return (input + 1);
	}
}

void set_count() {
	int temp = 1;
	for (int i = 1; i < MAX; i++) {
		temp = i;
		while (true) {
			if (temp == 1) {
				array_is_counted[i] = true;
				break;
			}
			else {
				temp = next_step(temp);
				array_count[i] += 1;
				if (array_is_counted[temp] == true) {
					array_count[i] += array_count[temp];
					array_is_counted[i] = true;
					break;
				}
			}

		}
	}
}

int main() {
	int * array_test_result = (int*)malloc(sizeof(int) * TEST_MAX);

	for (int i = 0; i < MAX; i++) {
		array_count[i] = 0;
		array_is_counted[i] = false;
	}

	set_count();

	cin >> t;

	int start = 0, end = 0;
	int total = 0;
	
	for (int i = 0; i < t; i++) {
		array_test_result[i] = 0;
		total = 0;
		cin >> start >> end;
		for (int j = start; j <= end; j++) {
			total += array_count[j];
		}
		array_test_result[i] = total;
	}

	for (int i = 0; i < t; i++) {
		printf("Case #");
		printf("%d\n", i + 1);
		printf("%d\n", array_test_result[i]);
	}


	return 0;
}