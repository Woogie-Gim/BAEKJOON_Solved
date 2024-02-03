#include<iostream>
#include<algorithm>
 
using namespace std;
 
int binary_search(int start, int end, int s[])
{
    if((s[start] + s[end]) % 2) return 0;
 
    int target = (s[start] + s[end]) / 2;
    int mid = (start + end) / 2;
 
    while(start <= end)
    {
        if(s[mid] == target) return 1;
        else if(s[mid] < target) start = mid+1;
        else end = mid-1;
 
        mid = (start + end) / 2;
    }
 
    return 0;
}
 
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
 
    int T;
    cin>>T;
 
    for(int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        
        int s[N], ans=0;
 
        for(int i = 0; i < N; i++)
            cin >> s[i];
 
        sort(s, s + N);
 
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 2; j < N; j++)
            {
                ans += binary_search(i, j, s);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}