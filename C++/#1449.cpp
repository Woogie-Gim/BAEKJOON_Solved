#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	int N;             
	int L;         
	int location[1000]; 
	int start;  
	int tape = 0;

	cin >> N >> L;

	for (int i = 0; i < N; i++) 
    {
		cin >> location[i];
	}

	sort(location, location + N);

	start = location[0];

	for (int i = 1; i < N; i++) 
    {
		if (L <= location[i] - start) 
        {
			tape++;		
			start = location[i];
		}
	}
	
	cout << tape + 1;

	return 0;
}