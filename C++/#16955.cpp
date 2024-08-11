#include<iostream>

using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

char board[10][10];

int check(int x, int y) 
{
	for (int i = 0; i < 8; i++) 
    {

		int cx = x;
		int cy = y;

		int cnt = 1;
		int empty = 0;

		for (int j = 0; j < 4; j++) 
        {
			int current_x = cx + dx[i];
			int current_y = cy + dy[i];

			if (0 <= current_x && current_x < 10 && 0 <= current_y && current_y < 10)
            {
				if (board[current_x][current_y] == 'X') 
                {
					cnt++;
				}
				if (board[current_x][current_y] == '.')
                {
					empty++;
				}
				cx = current_x;
				cy = current_y;
			}

			else 
            {
				break;
			}
		}
		if (cnt == 4 && empty == 1) return 1;

	}
	return 0;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++) 
    {
		for (int j = 0; j < 10; j++) 
        {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 10; i++) 
    {
		for (int j = 0; j < 10; j++) 
        {
			if (board[i][j] == 'X') 
            {
				if (check(i, j)) 
                {
					cout << 1 << '\n';
					return 0;
				}
			}
		}
	}
	cout << 0 << '\n';

	return 0;
}