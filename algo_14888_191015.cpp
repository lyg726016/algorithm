#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a_input[12];
int b_input[4];

int main(){
	int input_n;
	cin >> input_n;
	string cal;

	for (int i = 0; i < input_n; i++){
		cin >> a_input[i];
	}

	for (int i = 0; i < 4; i++){
		cin >> b_input[i];
	}

	//+ , -, x, / ¼ø¼­
	for (int i = 0; i < 4; i++){
		while (b_input[i] > 0){
			switch (i)
			{
			case 0:
				cal += '0';
				break;

			case 1:
				cal += '1';
				break;

			case 2:
				cal += '2';
				break;

			case 3:
				cal += '3';
				break;

			default:
				break;
			}
			b_input[i]--;
		}
	}

	int min_v = 1000000001 ;
	int max_v = -1000000001;

	do{
		string temp = cal;
		int result = a_input[0];

		for (int i = 0; i < input_n - 1; i++){
			if (temp[i] == '0'){
				result += a_input[i + 1];
			}
			if (temp[i] == '1'){
				result -= a_input[i + 1];
			}
			if (temp[i] == '2'){
				result *= a_input[i + 1];
			}
			if (temp[i] == '3'){
				result /= a_input[i + 1];
			}
		}

		if (result < min_v)
			min_v = result;
		if (result > max_v)
			max_v = result;

	} while (next_permutation(cal.begin(), cal.end()));

	cout << max_v << '\n';
	cout << min_v;

	return 0;
}