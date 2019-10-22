#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, K;
ll order(ll val) { // val�� ���ų� ���� ���� �� ���� �ִ���
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += min(N, val / i);
		if (i > val)
			break;
	}
	return sum;
}
int main(void) {

	scanf("%lld %lld", &N, &K);
	// order(i) < K�� �����ϴ� ���� ū i�� ã�� i+1�� ����ϸ� �ȴ�.
	ll left = 0;
	ll right = N*N;
	// i�� left~right�� ����
	while (right != left) {
		ll mid = (left + right) / 2 + 1;
		if (order(mid) >= K) {
			right = mid - 1;
		}
		else {
			left = mid;
		}
	}
	printf("%lld", left + 1);
}