#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int x[100001];
int y[100001];
int arr[100000];

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int num, animal, len;
    
    cin >> num >> animal >> len;
    
    for(int i=0;i<num;i++)
        cin>>arr[i];
    
    sort(arr,arr+num);
    
    for(int i=0;i<animal;i++)
        cin>>x[i]>>y[i];
    
    int result=0;
    
    for(int k=0;k<animal;k++)
    {
        int l = 0,r = num - 1, mid;
        while(l<=r)
        {
            mid = l + (r - l) / 2;
            int cal = abs(arr[mid] -x [k]) + y[k];
            if(cal <= len)
            {
                result++;
                break;
            }
            else
            {
                if(x[k] >= arr[mid])
                    l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    cout << result;
    return 0;
}