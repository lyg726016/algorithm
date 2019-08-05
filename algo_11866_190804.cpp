#include <iostream>
#include <queue>

using namespace std;

int input_s;
int input_k;

queue <int> q;
int temp_q;

int main(){

	cin >> input_s >> input_k;

	int temp = input_s;

	for (int i = 1; i <= input_s; i++){
		q.push(i);
	}
	cout << "<";
	while (temp){
		for (int i = 1; i <= input_k; i++){
			temp_q = q.front();
			q.pop();
			if (i != input_k)
				q.push(temp_q);
			else{
				if (temp != 1)
				cout << temp_q << ", ";
				else
					cout << temp_q << ">";
			}
		}
		temp--;
	}

	return 0;
}