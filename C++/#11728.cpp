#include <iostream>

using namespace std;

int arr1[1000002];
int arr2[1000002];
int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
    {
		cin >> arr1[i];
	}
	for (int i = 0; i < M; i++) 
    {
		cin >> arr2[i];
	}
	
	int i = 0, j = 0;
    
	while (i < N && j < M) 
    {
		if (arr1[i] < arr2[j]) 
        {
			cout << arr1[i++] << " ";
		}
		else 
        {
			cout << arr2[j++] << " ";
		}
	}
    
	while (i < N) cout << arr1[i++] << " ";
	while (j < M)cout << arr2[j++] << " ";
	
	return 0;
}