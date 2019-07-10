#include <iostream>

using namespace std;

//https://www.acmicpc.net/submit/16674

//condition a
//숫자가 2 0 1 8 로만 이루어짐 = 관련있는 수
#define RELATED_NUMBER 1

//condition b 
//2 0 1 8  각각을 1회 이상 포함
#define LOT_RELATED_NUMBER 2

//condition c
//2 0 1 8 각각을 1회 이상 포함하며, 모두 동일한 개수
#define LOT_LOT_RELATED_NUMBER 8

//condition d
//2 0 1 8 이외의 수 1회 이상 
#define NOT_RELATED_NUMBER 0

#define MAX_CHAR 1000000000

int main() {

	char input_c;
	int number[10];

	for (int i = 0; i < 10; i++) {
		number[i] = 0;
	}

	for (int i = 0; i < MAX_CHAR; i++) {
		input_c = getchar();

		if (input_c == '0')
			number[0]++;
		else if (input_c == '1')
			number[1]++;
		else if (input_c == '2')
			number[2]++;
		else if (input_c == '3')
			number[3]++;
		else if (input_c == '4')
			number[4]++;
		else if (input_c == '5')
			number[5]++;
		else if (input_c == '6')
			number[6]++;
		else if (input_c == '7')
			number[7]++;
		else if (input_c == '8')
			number[8]++;
		else if (input_c == '9')
			number[9]++;
		else
			break;
	}
	//2 0 1 8
	//로만 이루어진, 개수가 같은 
	if (number[3] == 0 && number[4] == 0 && number[5] == 0 && number[6] == 0 && number[7] == 0 && number[9] == 0) {
		if (number[0] == number[1] && number[1] == number[2] && number[2] == number[8] )
			cout << LOT_LOT_RELATED_NUMBER;
		else if (number[0] > 0 && number[1] > 0 && number[2] > 0 && number[8] > 0)
			cout << LOT_RELATED_NUMBER;
		else
			cout << RELATED_NUMBER;
	}
	else {
		cout << NOT_RELATED_NUMBER;
	}

	return 0;
}