#include<iostream>
#include<vector>
#include<cmath>

#define endl "\n"
#define MAX 20
using namespace std;

int N, Answer = 999999;
int MAP[MAX][MAX];
bool Select[MAX];

int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

int Calculate_Synergy(vector<int> V)
{
	int Sum = 0;
	for (int i = 0; i < V.size(); i++)
	{
		for (int j = 0; j < V.size(); j++)
		{
			if (i == j) continue;
			Sum = Sum + MAP[V.at(i)][V.at(j)];
		}
	}
	return Sum;
}

void Calculate()
{
	vector<int> Link, Start;

	for (int i = 0; i < N; i++)
	{
		if (Select[i] == true) Link.push_back(i);
		else Start.push_back(i);
	}

	int Synergy_Link = Calculate_Synergy(Link);
	int Synergy_Start = Calculate_Synergy(Start);
	int Diff = abs(Synergy_Link - Synergy_Start);

	Answer = Min(Answer, Diff);
}

void Divide_Team(int Index, int Cnt)
{
	if (Cnt == N / 2)
	{
		Calculate();
		return;
	}

	for (int i = Index; i < N; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;
		Divide_Team(i, Cnt + 1);
		Select[i] = false;
	}
}

void Solution()
{
	Divide_Team(0, 0);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}
