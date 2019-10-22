#include <iostream>

using namespace std;
int a_c[1000001];
int main(){
	int r_c;
	cin >> r_c;

	for (int i = 0; i < r_c; i++){
		cin >> a_c[i];
	}

	int f_s, s_s;
	cin >> f_s >> s_s;

	int temp;
	int c_s_s;
	long long total_v = 0;
	for (int i = 0; i < r_c; i++){
		temp = a_c[i] - f_s;
		total_v += 1;

		c_s_s = temp / s_s;
		if (temp > 0){
			if (temp % s_s == 0){
				total_v += c_s_s;
			}
			else{
				total_v += (c_s_s + 1);
			}
		}
	}

	cout << total_v;

	return 0;
}