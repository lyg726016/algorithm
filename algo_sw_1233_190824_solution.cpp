#include<iostream>
#include<string.h>
using namespace std;
char arr[201] = { 0 };

int main() {
	int n;
	for (int t = 1; t <= 10; t++) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		for (int i = 1; i <= n; i++) {//입력
			int node;
			char v;
			cin >> node >> v;
			if (n % 2 == 0 && n / 2 > i || n % 2 == 1 && n / 2 >= i) {//자식 2개
				scanf("%*d %*d");
			}
			else if (n % 2 == 0 && n / 2 == i) {//자식 1개
				scanf("%*d");
			}
			arr[node] = v;
		}
		for (int i = 1; i <= n; i++) {
			if (n / 2 < i) {//리프노드 == 숫자
				if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {
					printf("#%d 0\n", t); break;
				}
				else printf("#%d 1\n", t); break;
			}
			else if (n / 2 >= i) {//리프노드가 아닌 노드 == 기호
				if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {}
				else {
					printf("#%d 0\n", t); break;
				}
			}
		}
	}
}