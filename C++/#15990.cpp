#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector < vector <unsigned long long> > num(100001, vector <unsigned long long>(4, 0));
   
	num[1][1] = 1;
    
	num[2][2] = 1;
    
	num[3][1] = 1;
	num[3][2] = 1;
	num[3][3] = 1;
	
	int T;
	cin >> T;
    
	while (T--)
	{
		long long n;
		cin >> n;
		for (int i = 4; i < n+1; i++)
		{

			num[i][1] = (num[i - 1][3] + num[i - 1][2]) % 1000000009;
			num[i][2] = (num[i - 2][1] + num[i - 2][3]) % 1000000009;
			num[i][3] = (num[i - 3][1] + num[i - 3][2]) % 1000000009;
		}

		cout << (num[n][1] + num[n][2] + num[n][3]) % 1000000009<<'\n';
	}
}