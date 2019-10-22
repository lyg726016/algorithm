#include <iostream>

using namespace std;

int i_a[8][8];
int result = 0;
int main(){

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			cin >> i_a[i][j];
			//00 го╬А╩Ж 02 го╬А╩Ж
			//10 ╟ка╓╩Ж

			if (i % 2 == 0 && j % 2 == 0){
				if (i_a[i][j] != '.'){
					result++;
				}
			}
		}
	}
	return 0;
}