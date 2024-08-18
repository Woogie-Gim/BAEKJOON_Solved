#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct Pos 
{
	int x, y;
};

int N, M;
int A[51][51];
bool Cloud[51][51];
bool c_Cloud[51][51];
deque<Pos>p_Cloud;
const int dxy[][2] = { {0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };

void MoveCloud(int d, int s) 
{
	memset(Cloud, false, sizeof(Cloud));
    
	int cloud_cnt = p_Cloud.size();
    
	for (int i = 0; i < cloud_cnt; i++) 
    {
		int x = p_Cloud.front().x;
		int y = p_Cloud.front().y;
		p_Cloud.pop_front();
		int rs = s % N;
        
		while (rs--) 
        {
			x += dxy[d][0];
			y += dxy[d][1];
			if (x > N)
				x = 1;
			else if (x <= 0)
				x = N;
			if (y > N)
				y = 1;
			else if (y <= 0)
				y = N;
		}
		p_Cloud.push_back({ x,y });
		Cloud[x][y] = true;
	}
}

void Rain() 
{
	int cloud_cnt = p_Cloud.size();
	for (int i = 0; i < cloud_cnt; i++) 
    {
		int x = p_Cloud[i].x;
		int y = p_Cloud[i].y;
		A[x][y]++;
	}
}

void Copy() 
{
	int cloud_cnt = p_Cloud.size();
	for (int i = 0; i < cloud_cnt; i++) 
    {
		int x = p_Cloud[i].x;
		int y = p_Cloud[i].y;
		int water_cnt = 0;
        
		for (int d = 2; d <= 8; d += 2) 
        {
			int nx = x + dxy[d][0];
			int ny = y + dxy[d][1];
			if (nx <= 0 || nx > N || ny <= 0 || ny > N)
				continue;
			if (A[nx][ny] > 0)
				water_cnt++;
		}
		A[x][y] += water_cnt;
	}

    p_Cloud.clear();
}

void makeCloud() 
{
	for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= N; j++) 
        {
			c_Cloud[i][j] = Cloud[i][j];
			Cloud[i][j] = false;
		}
	}
	for (int i = 1; i <= N; i++)
    {
		for (int j = 1; j <= N; j++) 
        {
			if (A[i][j] >= 2 && c_Cloud[i][j] == false) 
            {
				p_Cloud.push_back({ i,j });
				Cloud[i][j] = true;
				A[i][j] -= 2;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= N; j++) 
        {
			cin >> A[i][j];
		}
	}

    p_Cloud.push_back({ N,1 });
	p_Cloud.push_back({ N,2 });
	p_Cloud.push_back({ N - 1,1 });
	p_Cloud.push_back({ N - 1,2 });

	int d, s;

	for (int i = 0; i < M; i++) 
    {
		cin >> d >> s;
		MoveCloud(d, s);
		Rain();
		Copy();
		makeCloud();
	}
    
	int answer = 0;
    
	for (int i = 1; i <= N; i++) 
    {
		for (int j = 1; j <= N; j++)
        {
			answer += A[i][j];
		}
	}
	cout << answer << '\n';
    
	return 0;
}