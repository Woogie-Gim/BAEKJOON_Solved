#include <iostream>
#include <vector>

using namespace std;

int V, E;
int arr[401][401];
int res = 987654321;

int main()
{
	int a, b, c;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	
	for(int i=1;i<=V;i++)
		for (int j = 1; j <= V; j++)
		{
			if (arr[i][j] == 0)
				arr[i][j] = 987654321;
		}

	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
					if (i == j)
						res = min(res, arr[i][j]);
				}

	if (res == 987654321)
		cout << "-1";
	else
		cout << res;
}