
#include <iostream>
using namespace std;

int n, p[40][40], m;

void foo() 
{
	for (int i = 0; i < n; i++)
    {
		int mcnt = 0;
		for (int j = 0; j < n; j++) 
        {
			if (p[i][j] == m) mcnt++;
		}
		if (mcnt > n / 2)
        {
			for (int j = 0; j < n; j++) 
            {
				p[i][j] = m;
			}
		}
	}
    
	for (int j = 0; j < n; j++)
    {
		int mcnt = 0;
		for (int i = 0; i < n; i++)
        {
			if (p[i][j] == m) mcnt++;
		}
		if (mcnt > n / 2) 
        {
			for (int i = 0; i < n; i++) 
            {
				p[i][j] = m;
			}
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
    
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++) 
        {
			cin >> p[i][j];
		}
	}
    
	foo();
	foo();
	
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++) 
        {
			if (p[i][j] != m) 
            {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
}