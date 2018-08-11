#include <iostream>
#include <vector>
const int MAX_NODES = 505;
const int INFINIT = 65535;
using namespace std;
vector<vector<int> >Graph(MAX_NODES,vector<int>(MAX_NODES,INFINIT));
vector<bool>visited(MAX_NODES, false);

int routes = 0;
int team_nums = 0;
int mincost = 65535;

void DFS(int S, int D, int N,int pre_cost,int pre_teams)
{
	for (int i = 0; i < N; ++i)
	{
		if (i != S && visited[i] == false&&Graph[S][i]<INFINIT)
		{
			if (i == D)
			{
				if (pre_cost + Graph[S][i] < mincost)
				{
					mincost = pre_cost + Graph[S][i];
					team_nums = pre_teams + Graph[i][i];
					routes = 1;
				}
				else if (pre_cost + Graph[S][i] == mincost)
				{
					routes++;
					if (team_nums < pre_teams + Graph[i][i])
						team_nums = pre_teams + Graph[i][i];
				}
			}
			else
			{
				visited[S] = true;
				DFS(i, D, N, pre_cost + Graph[S][i], pre_teams + Graph[i][i]);
				visited[S] = false;
			}
		}
	}
}
int main()
{
	int N, E, S, D;
	cin >> N >> E >> S >> D;
	for (int i = 0; i < N; ++i)
		cin >> Graph[i][i];
	while (E--)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		Graph[v1][v2] = w;
		Graph[v2][v1] = w;
	}
	if (N != 0)
	{
		if (S == D)
		{
			cout << 1 << " " << Graph[S][S];
		}
		else
		{
			DFS(S, D, N, 0, Graph[S][S]);
			cout << routes << " " << team_nums;
		}
	}
	return 0;
}