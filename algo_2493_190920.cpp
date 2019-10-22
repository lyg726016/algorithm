#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;
int input_n;
int temp;
int a_r[500001];

int main(){

	cin >> input_n;
	cin >> temp;
	a_r[0] = 0;

	s.push(make_pair(1, temp));

	for (int i = 2; i <= input_n; i++){
		cin >> temp;

		while (true)
		{
			if (s.empty()){
				a_r[i] = 0;
				s.push(make_pair(i, temp));
				break;
			}
			else{
				pair<int, int> p_t = s.top();
				if (p_t.second > temp){
					a_r[i] = p_t.first;
					s.push(make_pair(i, temp));
					break;
				}
				else{
					s.pop();
				}
			}
		}
	}

	for (int i = 1; i < input_n; i++){
		cout << a_r[i] << " ";
	}
	cout << a_r[input_n];

	return 0;
}