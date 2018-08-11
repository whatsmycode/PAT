#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
bool cmp(vector<string>vs1, vector<string>vs2)
{
	if (vs1.size() == 0 && vs2.size() == 0)
		return true;
	else if (vs1.empty() || vs2.empty())
		return false;
	else
		return vs1[0] < vs2[0];
}
int main()
{
	int node_sum, non_leaf;
	cin >> node_sum >> non_leaf;
	vector<vector<string>>tree(100);
	while (non_leaf--)
	{
		string id;
		int n;
		cin >> id >> n;
		vector<string>str = { id };
		while (n--)
		{
			string s;
			cin >> s;
			str.push_back(s);
		}
		tree[stoi(id)] = str;
	}
	if (tree[1].size() == 0)
		cout << 1;
	else
	{
		queue<string>q1;
		q1.push(tree[1][0]);
		queue<string>q2;
		while (q1.size() || q2.size())
		{
			int level1 = 0;
			while (q1.size())
			{
				string nt = q1.front();
				q1.pop();
				int id = stoi(nt);
				if (tree[id].size() == 0)
					level1++;
				else
				{
					for (size_t i = 1; i < tree[id].size(); ++i)
						q2.push(tree[id][i]);
				}
			}
			if (!q2.empty())
				cout << level1 << " ";
			else
			{
				cout << level1;
				break;
			}
			level1 = 0;
			while (q2.size())
			{
				string nt = q2.front();
				q2.pop();
				int id = stoi(nt);
				if (tree[id].size() == 0)
					level1++;
				else
				{
					for (size_t i = 1; i < tree[id].size(); ++i)
						q1.push(tree[id][i]);
				}
			}
			if (!q1.empty())
				cout << level1 << " ";
			else
			{
				cout << level1;
				break;
			}
		}
	}
	return 0;
}