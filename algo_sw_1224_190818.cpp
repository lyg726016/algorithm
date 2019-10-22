#include <iostream>
#include <string>

using namespace std;

string s_input;
int count_input;
int i;
long long result;


int main(){

	for (i = 1; i < 11; i++){
		cin >> count_input;
		cin >> s_input;


		cout << "#" << i << " ";
		cout << result << '\n';
	}

	return 0;
}