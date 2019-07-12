#include<iostream>
#include<queue>

using namespace std;

//��ü ��� ��
int count_man;
//���� ��
int count_rel;
//���� a,b
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
			//���� �����̰�, �湮�� ���� ���ٸ�
			if (is_family[temp][j] == 1 && !visit[j])
			{
				//�湮, depth +1
				visit[j] = true;
				depth[j] = depth[temp] + 1;
				q.push(j);
			}
		}
	}
}

int main()
{
	//��� ��
	cin >> count_man; 
	//���� a,b
	cin >> input_a >> input_b; 
	//���� ��
	cin >> count_rel;

	//�θ� �ڽ� ����
	int parent, child;

	//�θ� �ڽ� ����
	for (int i = 1; i <= count_rel; i++)
	{
		cin >> parent >> child;

		//parent, child ���� ���� true
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