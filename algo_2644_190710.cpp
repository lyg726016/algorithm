#include<iostream>
#include<queue>

using namespace std;

//전체 사람 수
int count_man;
//관계 수
int count_rel;
//문제 a,b
int input_a, input_b; 

int depth[101];
bool is_family[101][101];
bool visit[101];

queue <int> q;

void bfs(int input)
{
	visit[input] = true;
	q.push(input);
	int temp;

	while (!q.empty())
	{
		temp = q.front(); 
		q.pop();
		
		for (int j = 1; j <= count_man; j++)
		{
			//가족 관계이고, 방문한 적이 없다면
			if (is_family[temp][j] == 1 && !visit[j])
			{
				//방문, depth +1
				visit[j] = true;
				depth[j] = depth[temp] + 1;
				q.push(j);
			}
		}
	}
}

int main()
{
	//사람 수
	cin >> count_man; 
	//문제 a,b
	cin >> input_a >> input_b; 
	//관계 수
	cin >> count_rel;

	//부모 자식 관계
	int parent, child;

	//부모 자식 관계
	for (int i = 1; i <= count_rel; i++)
	{
		cin >> parent >> child;

		//parent, child 가족 관계 true
		is_family[parent][child] = true;
		is_family[child][parent] = true;
	}

	bfs(input_a);

	if (depth[input_b] != 0)
		cout << depth[input_b] << endl;

	else
		cout << "-1" << endl;

	return 0;
}