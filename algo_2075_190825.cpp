#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int count_data;
int temp;
//pq 기본 내림차순
priority_queue<int> pq;
int i;
int sq_count_data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> count_data;
	sq_count_data = count_data * count_data;
	while (sq_count_data--){
		cin >> temp;
		//역순으로 넣음 -> 가장 작은 값이 제일 앞
		pq.push(-temp);
		//사이즈가 크면 가장 작은 값 빼버림
		if (pq.size() > count_data)
			pq.pop();
	}
	//5개중 가장 작은값 => 5번째로 큰 값
	cout << -pq.top();
	return 0;
}