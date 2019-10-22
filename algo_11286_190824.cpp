#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct data_a
{
	int input_v;
};

class my_comp
{
public:
	bool operator() (data_a input_a, data_a input_b)
	{
		if (abs(input_a.input_v) > abs(input_b.input_v)){
			return true;
		}
		else if (abs(input_a.input_v == abs(input_b.input_v))){
			if (input_a.input_v > input_b.input_v){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
};

int count_data;
int temp;
priority_queue<data_a, vector<data_a>, my_comp> pq;
int count_pq = 0;
data_a temp_data;
int i;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> count_data;
	while (count_data--){
		cin >> temp;
		if (temp){
			temp_data.input_v = temp;
			pq.push(temp_data);
			count_pq++;
		}
		else{
			if (count_pq){
				cout << pq.top().input_v << '\n';
				pq.pop();
				count_pq--;
			}
			else{
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}