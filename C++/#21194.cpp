#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,res;
int arr[100001];

int main()
{
    cin >> n>>k;
    
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    sort(arr,arr+n);
    
    for(int i=n-1;i>n-k-1;i--)
        res+=arr[i];
    
    cout << res;
}