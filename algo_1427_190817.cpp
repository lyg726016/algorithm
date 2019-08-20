#include <iostream>
#include <string>

using namespace std;

int i, cnt[10];
string str;

int main() {
	cin >> str;
	for (i = 0; i < str.length(); i++){
		cnt[str[i] - '0']++;
	}

	for (i = 9; i >= 0; i--){
		while (cnt[i]--) {
			cout << i;
		}
	}

	return 0;
}