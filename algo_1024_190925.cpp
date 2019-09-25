#include <cstdio>
int main() {

	int N, L;
	int sum = 0;
	scanf("%d%d", &N, &L);
	if (N % 2 == 0 && L == 2)
		L = 3;

	for (int i = L; i <= 100; i++) {
		int K, C;

		if (i % 2 == 0) {
			K = N / i;
			if (N%i != i / 2) continue;
			C = K - (i - 1) / 2;

		}
		else {
			K = N / i;
			if (N%i != 0) continue;
			C = K - i / 2;
		}
		if (C >= 0) {
			for (int j = 0; j<i; j++) {
				printf("%d ", C + j);
			}
			printf("\n");
			return 0;
		}
		else break;
	}

	printf("-1\n");
	return 0;
}