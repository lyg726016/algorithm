#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;

int main() {
	vector<int> intVec = { 4,5,9,8 };

	//��� permutation�� ��� ���� ������ �ʿ��ϴ�.
	std::sort(intVec.begin(), intVec.end());

	//bool���� ��ȯ�� ������ �ݺ��Ѵ�.
	do {
		for (auto it = intVec.begin(); it != intVec.end(); ++it)
			std::cout << *it << ' ';
		std::cout << std::endl;
	} while (std::next_permutation(intVec.begin(), intVec.end()));


	return 0;
}
