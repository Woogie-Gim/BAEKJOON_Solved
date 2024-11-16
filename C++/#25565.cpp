#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

#define MAX 2010
using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int cnt = 0,n,m,k,board[MAX][MAX];
vector<pair<int,int> > v;

struct info
{
	
	int y;
	int x;
	int dir;
	
};

int visited[MAX][MAX];
queue<info> q;

void init() 
{
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
        {
			cin >> board[i][j];
			if(board[i][j]) cnt++;
		}
	}

}

int isRange(int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
	if(a.first == b.first)
    {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void intersection(int y, int x)
{
	
	memset(visited,0,sizeof(visited));

	if(k == 1)
    {
		v.push_back({y,x});
		return;
	}
	
	int origin_y = y; int origin_x = x;
	visited[y][x] = 1;
	
	int cnt = 0;
	for(int i = 0; i < 4; i++)
    {
		
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(isRange(ny,nx) && board[ny][nx]){
			visited[ny][nx] = 1;
			q.push({ny,nx,i});
			cnt++;
		}
		
	}
    
	if(cnt >= 2)
    {
		v.push_back({y,x});
		return;
	}
	
	while(!q.empty()) 
    {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		
		for(int i = 0; i < 4; i++)
        {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(!isRange(ny,nx)) continue;
			if(!board[ny][nx]) continue;
			if(visited[ny][nx]) continue;
			
			if(dir != i)
            {
				v.push_back({y,x});
				return;
			}
			
			visited[ny][nx] = 1;
			q.push({ny,nx,i});
		}
	}
	
	if(!v.size())
    {
		
		int y = origin_y;
		int x = origin_x;
		
		for(int i = 0; i < k - 1; i++)
        {
			y += dy[0];
			x += dx[0];
		}
		
		if(board[y][x] == 1)
        {
			v.push_back({y,x});
		}
		 
		y = origin_y;
		x = origin_x;
		
		for(int i = 0; i < k - 1; i++)
        {
			y += dy[2];
			x += dx[2];
		}
		
		if(board[y][x] == 1)
        {
			v.push_back({y,x});
		}
	}
	
}

void findIntersection() 
{
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
        {
			if(board[i][j])
            {
				intersection(i,j);
				return;
			}
		}
	}
	
}

void findFruit() 
{
	
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
        {
			if(board[i][j]) v.push_back({i,j});
		}
	}

}

pair<int,int> findFruit2() 
{
	
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
        {
			if(board[i][j]) return {i,j};
		}
	}
	
}

void solve() 
{
	
	if(cnt == (k * 2))
    {
		return;
	} else if(cnt == (k * 2) - 1)
    {
		findIntersection();
	} else if(cnt == (k * 2) - k)
    {
		findFruit();
	} 
    else
    {
		int haveFruit = (k * 2) - cnt;
		int all_range = cnt;
		int start = (all_range - haveFruit) / 2;

		pair<int,int> temp = findFruit2();
		
		int y = temp.first;
		int x = temp.second; // (0,0)

		int down_y = y + dy[0];
		int down_x = x + dx[0];
		int right_y = y + dy[2];
		int right_x = x + dx[2];
		
		if(board[down_y][down_x] == 1)
        {
			for(int i = y + start; i < y + start + haveFruit; i++)
            {
				v.push_back({i,x});
			}
		} 
        else if(board[right_y][right_x] == 1)
        {
			for(int i = x + start; i < x + start + haveFruit; i++)
            {
				v.push_back({y,i});
			}
		}
	}
	if(v.size()) sort(v.begin(), v.end(), cmp);
	
}

int main() 
{
	
	init();
	solve();
	
	cout << v.size() << "\n";
    
	for(int i = 0; i < v.size(); i++)
    {
		cout << v[i].first + 1 << " " << v[i].second + 1 << "\n";	
	}
	
	return 0;
}