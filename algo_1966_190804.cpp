#include <iostream>
#include <queue>

using namespace std;

int tc;
int count_d;
int target_n;
int input_a;
int target_value;

int count_value;
pair <int, int> temp;

bool is_exist = false;

int main(){

	cin >> tc;

	for (int i = 0; i < tc; i++){
		cin >> count_d >> target_n;
		count_value = 0;

		queue <pair <int, int>> q;
		priority_queue <int> pq;

		for (int i = 0; i < count_d; i++){
			cin >> input_a;

			if (i == target_n)
				target_value = input_a;

			q.push(make_pair(input_a, i));
			pq.push(input_a);
		}
		//6 0
		//1 1 9 1 1 1
		while (true)
		{
			temp = q.front();
			q.pop();
			if (temp.first == pq.top()){
				pq.pop();
				count_value++;
				if (temp.first == target_value){
					if (temp.second == target_n){
						cout << count_value << '\n';
						break;
					}
					else{

					}
				}
			}
			else{
				q.push(temp);
			}
		}
	}

	return 0;
}