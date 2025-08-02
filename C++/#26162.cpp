#include <iostream>

using namespace std;

int arr[150];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
    cout.tie(0);

	arr[0] = 1;	
    arr[1] = 1;
    
	for (int i = 2; i < 150; i++) 
    {
		for (int j = 2; i * j < 150; j++) 
        {
			arr[i * j]++;
		}
	}

	int n;
    
	cin >> n;
    
	for (int i = 0; i < n; i++) 
    {
		int num;
		cin >> num;

		int possible = 0;
        
		for (int i = 2; i < num; i++) 
        {
			if (arr[i] == 0 && arr[num - i] == 0) 
            {
				possible++;
				break;
			}
		}

		if (possible > 0) 
        { 
            cout << "Yes" << "\n"; 
        }
		else 
        { 
            cout << "No" << "\n"; 
        }
	}
}