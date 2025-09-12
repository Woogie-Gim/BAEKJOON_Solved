#include <iostream>

using namespace std;

int n, p[1001][1001];
int x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
    
	cin >> x >> y;
    
	x--; 
    y--;
    
	for (int i = 0; i < n; i++) 
    {
		for (int j = 0; j < n; j++) 
        {
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < n; i++) 
    {
		if (p[i][y] > p[x][y]) 
        {
			cout << "ANGRY";
			return 0;
		}
        
		if (p[x][i] > p[x][y]) 
        {
			cout << "ANGRY";
			return 0;
		}
	}
	cout << "HAPPY";
    
    return 0;
}