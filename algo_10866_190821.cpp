#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);

	deque<int> deq;

	int N;
	cin >> N;

	while (N--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push_front")
		{
			int num;
			cin >> num;
			deq.push_front(num);
		}

		else if (cmd == "push_back")
		{
			int num;
			cin >> num;
			deq.push_back(num);
		}

		else if (cmd == "pop_front")
		{
			if (!deq.empty()) {
				cout << deq.front() << endl;
				deq.pop_front();
			}
			else
				cout << -1 << endl;
		}

		else if (cmd == "pop_back")
		{
			if (!deq.empty()) {
				cout << deq.back() << endl;
				deq.pop_back();
			}
			else
				cout << -1 << endl;
		}

		else if (cmd == "front")
		{
			if (!deq.empty())
				cout << deq.front() << endl;
			else
				cout << -1 << endl;
		}

		else if (cmd == "back")
		{
			if (!deq.empty())
				cout << deq.back() << endl;
			else
				cout << -1 << endl;
		}

		else if (cmd == "size")
			cout << deq.size() << endl;

		else if (cmd == "empty")
			cout << deq.empty() << endl;
	}
}