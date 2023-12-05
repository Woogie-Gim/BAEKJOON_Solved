#include<iostream>
#include<algorithm>
#include <cmath>
#include<vector>
#include <queue>
using namespace std;

int people[11];
int visit[11];
int visit_2[11];
vector< vector<int> > v(11);
int n;
int answer = 987654321;
int sum_1 = 0;
int sum_2 = 0;
int flag;



void possible()
{
	vector<int> team_1, team_2;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		visit_2[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
			team_1.push_back(i);
		else
			team_2.push_back(i);
	}

	q.push(team_1[0]);
	visit_2[team_1[0]] = 1;
	int count = 1;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < v[a].size(); i++)
		{
			if (find(team_1.begin(), team_1.end(), v[a][i]) != team_1.end())
			{
				if (visit_2[v[a][i]] == 0)
				{
					count++;
					visit_2[v[a][i]] = 1;
					q.push(v[a][i]);
				}
			}
		}
	}

	if (count != team_1.size())
		flag = 0;


	count = 1;
	q.push(team_2[0]);
	visit_2[team_2[0]] = 1;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < v[a].size(); i++)
		{
			if (find(team_2.begin(), team_2.end(), v[a][i]) != team_2.end())
			{
				if (visit_2[v[a][i]] == 0)
				{
					count++;
					visit_2[v[a][i]] = 1;
					q.push(v[a][i]);
				}
			}
		}
	}

	if (count != team_2.size())
		flag = 0;
}

void make_team(int now, int cnt, int size) 
{
	if (cnt == size)
	{
		flag = 1;
		possible();
		if (flag ==1 )
		{
			sum_1 = 0;
			sum_2 = 0;
			for (int i = 1; i <= n; i++)
			{
				if (visit[i] == 0)
					sum_1 += people[i];
				else
					sum_2 += people[i];

			}

			answer = min(answer, abs(sum_1 - sum_2));
		}
		return;
	}
	for (int i = now; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			make_team(i,cnt + 1, size);
			visit[i] = 0;
		}
	}
}

int main()
{
	int cnt,a;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> people[i];

	for (int i = 1; i <= n; i++)
	{
		cin >> cnt;
		for (int k = 0; k < cnt; k++)
		{
			cin >> a;
			v[i].push_back(a);
		}
	}

	
	for (int i = 1; i <= n/2; i++)
	{
		make_team(1, 0,i);
	}

	if (answer == 987654321)
		answer = -1;
	cout << answer;
	return 0;
}