#include <iostream>
#include <cstring>

using namespace std;

int arr[101];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x; 
    
    cin >> x;
    
	while (x > -1) 
    {
		if (x == 0) 
        {
			int ans = 0;
            
			for (int i = 1; i < 51; i++) 
            {
				if (arr[i] && arr[i * 2]) ans++;
			}
			cout << ans << '\n';
            
			memset(arr, 0, sizeof(arr));
		}
		else arr[x] = 1;
        
		cin >> x;
	}
}