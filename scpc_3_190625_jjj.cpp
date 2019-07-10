#include <iostream>
#include <vector>
#include <map>

#define MAX_Y 100000000000 + 5
#define MAX_JUMP 447214 + 1000

using namespace std;

int Answer;

typedef long long ll;

// °ª Á¡ÇÁ
vector<pair<ll, ll>> point;
ll cache[MAX_JUMP + 10] = { 0, };


int search(ll num) {
	if (num == 0) return 0;
	int sz = point.size();
	for (int i = 0; i < sz; i++) {
		pair<ll, ll> a = point[i];
		if (num == a.first) return i;
		else if (num < a.first) return i - 1;
	}
	return sz - 1;
}

ll proc(ll num) {
	if (num == 0) return 0;
	if (cache[num]) return cache[num];
	int idx = search(num);
	ll dist = num - point[idx].first;
	cache[num] = proc(dist);
	return cache[num];
}


int main(int argc, char** argv)
{
	int T, test_case;


	// freopen("input.txt", "r", stdin);

	// cin >> T;

	scanf_s("%d", &T);

	ll num = 0;
	ll jump = 0;
	while (1) {
		if (num > MAX_Y) break;
		//if (num > 100) break;
		point.push_back(make_pair(num, jump));
		//printf("%lld %lld\n", num, jump);
		jump++;
		num += jump;
	}

	//printf("\n\n");
	/*
	for (ll i = 0; i < MAX_JUMP; i++) {
		ll idx = search(i);
		ll dist = i - point[idx].first;
		ll value = point[idx].second + proc(dist);
		cache[i] = value;
		//printf("%lld ",i);
		//printf("%lld ", dist);
		//printf("%lld ", value);
		//printf("\n");
		//printf("%lld %lld %lld %lld\n", i,idx, point[idx].first,i- point[idx].first);
	}
	*/


	for (test_case = 0; test_case < T; test_case++)
	{
		ll x, y;
		scanf_s("%lld %lld", &x, &y);
		int idx_y = search(y);
		int idx_st = idx_y - 1;

		if (idx_st < 0) idx_st = 0;

		ll st;
		ll end = y;
		ll mx = 0;

		st = x > point[idx_st].first ? x : point[idx_st].first;

		for (; st <= end; st++) {
			if (st >= point[idx_y].first) idx_st = idx_y;
			ll dist = st - point[idx_st].first;
			ll v = point[idx_st].second + proc(dist);
			//printf("%lld %lld\n", st, v);
			mx = v > mx ? v : mx;
		}

		printf("Case #%d\n%lld\n", test_case + 1, mx);
	}

	return 0;//Your program should return 0 on normal termination.
}