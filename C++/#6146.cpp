#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int>P;

int arr[1001][1001];
int x, y, n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<P>q;

void bfs()
{
	while (!q.empty())
    {
		P now = q.front();
		q.pop();
        
		for (int i = 0; i < 4; i++) 
        {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || nx>1000 || ny < 0 || ny>1000)
				continue;
			if (arr[nx][ny]) continue;
			if (nx == x && ny == y) 
            {
				cout << arr[now.first][now.second];
				return;
			}
			arr[nx][ny] = arr[now.first][now.second] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() 
{
	ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
	cin >> x >> y >> n;
   
	x += 500; y += 500;
    
	for (int i = 0; i < n; i++) 
    {
		int x, y; cin >> x >> y;
		arr[x + 500][y + 500] = 2;
	}
    
	arr[500][500] = 1;
	q.push({ 500,500 });
	bfs();
    
	return 0;
}