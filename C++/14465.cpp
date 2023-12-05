#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() 
{
 
    int n, k, b;
    cin >> n >> k >> b;
    cin.ignore();
 
    vector<int> v(n + 1, 1);
    
    for(int i = 0; i < b; i++) 
    {
        int a;
        cin >> a;
        v[a] = 0;
    }
 

    int s = 1;
    int e = 1;
    int cnt = 0;
    int minCnt = 9999999;
 
    while (e < k) 
    {
        e++;
        if(v[e] == 0)
        {
            cnt++;
        }
    }
 
    while (e < n) 
    {
        minCnt = min(minCnt, cnt);
        s++;
        e++;
        if(v[e] == 0)
        {
            cnt++;
        }
        if(v[s] == 0) 
        {
            cnt--;
        }
    }
 
    cout << minCnt;
 
    return 0;
}
