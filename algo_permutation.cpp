#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;

int main() {
	vector<int> intVec = { 4,5,9,8 };

	//모든 permutation을 얻기 위해 정렬이 필요하다.
	std::sort(intVec.begin(), intVec.end());

	//bool값을 반환할 때까지 반복한다.
	do {
		for (auto it = intVec.begin(); it != intVec.end(); ++it)
			std::cout << *it << ' ';
		std::cout << std::endl;
	} while (std::next_permutation(intVec.begin(), intVec.end()));


	return 0;
}
