#include <iostream>
#include <vector>
#include <limits.h>
 
using namespace std;
 
int n;
vector<int> vec;
vector<int> prefix;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    vec.resize(n + 1);
    prefix.resize(n + 1);
 
    int temp;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> temp;
        vec[i] = temp;
        prefix[i] = prefix[i - 1] + temp;
    }
 
    int ans = INT_MAX;
    int answer = 0;
 
     for (int i = 1; i <= n; i++)
    {
        int s = i;
        int e = i + 1;
 
        while (s > 0 && e <= n)
        {
            int left = prefix[i] - prefix[s - 1];
            int right = prefix[e] - prefix[i];
 
            if (ans > abs(right - left))
            {
                ans = min(ans, abs(right - left));
                answer = prefix[e] - prefix[s - 1];
            }
            else if (ans == abs(right - left))
            {
                answer = max(answer, prefix[e] - prefix[s - 1]);
            }
 
            if (left >= right) e++;
            else s--;
        }
    }
 
    cout << answer;
 
    return 0;
}
