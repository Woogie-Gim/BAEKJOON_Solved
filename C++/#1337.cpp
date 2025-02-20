#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    vector<int> v;
    vector<int> sub;
    
    int n;
    
    cin >> n;
    
    while(n--) 
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 4;
    
    for(int i=0; i<v.size()-1; i++)
    {
        int tmp = 0, cnt = 1;
        for(int j=i; j<v.size()-1; j++)
        {
            if(cnt == 5)
            {
                ans = min(ans, tmp);
                break;
            }
            
            int cha = v[j+1] - v[j] - 1;
            tmp += cha;
            cnt += cha + 1;
        }
        
        if(cnt < 5) 
        {
            tmp += 5 - cnt;
            ans = min(ans, tmp);
        }
    }
    
    cout << ans;
    
    return 0;
}