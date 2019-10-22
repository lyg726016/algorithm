#include <iostream>
#include <string>

using namespace std;

int main(){
	int f_i, d_i;
	string s_i;
	cin >> s_i;
	cin >> d_i;

	int s_length = s_i.length();
	s_i[s_length - 2] = '0';
	s_i[s_length - 1] = '0';
	f_i = stoi(s_i);

	int left = f_i % d_i;

	for (int i = 0; i <= 99; i++){
		if (left + i == d_i){
			if (i < 10){
				cout << "0" << i;
				return 0;
			}
			else{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}