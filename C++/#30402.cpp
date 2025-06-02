#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
	char c;
    
	int i, j;
    
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			cin >> c;
			if (c == 'w')
			{
				cout << "chunbae";
				return 0;
			}
			if (c == 'b')
			{
				cout << "nabi";
				return 0;
			}
			if (c == 'g')
			{
				cout << "yeongcheol";
				return 0;
			}
		}
	}
}