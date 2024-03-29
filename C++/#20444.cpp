#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    long long n,k;
    cin >> n >> k;
    
    long long left = 0, right = n;
    string ans = "NO";
    
    while(left <= right) 
    {
        long long mid = (left + right) / 2;
        long long value = (mid + 1) * ((n - mid) + 1);
        
        if(value>k) {
            right = mid - 1;
        }
        else if(value < k) 
        {
            left = mid + 1;
        }
        else 
        {
            ans="YES";
            break;
        }
    }
    
    cout << ans << "\n";
    
}