#include <iostream>

using namespace std;

long long tc;
long long start_p, end_p;
long long distance_v;
long long max_v = 1;
long long result = 0;
long long temp;
long long arr_max_v[1000000];


int main() {
	cin >> tc;

	for (long long i = 0; i < 1000000; i++) {
		arr_max_v[i] = i * i;
	}

	for (int i = 0; i < tc; i++) {
		result = 0;
		max_v = 1;
		cin >> start_p >> end_p;
		distance_v = end_p - start_p;
		
		while (true) {
			if (distance_v < arr_max_v[max_v])
			{
				if(max_v != 1)	
					max_v -= 1;

				break;
			}
			max_v++;
		}

		temp = distance_v - arr_max_v[max_v];
		
		if (temp % max_v == 0) {
			result = (max_v * 2) - 1 + (temp / max_v);
		}
		else {
			result = (max_v * 2) + (temp / max_v);
		}
		cout << result;
	}

	

	return 0;
}