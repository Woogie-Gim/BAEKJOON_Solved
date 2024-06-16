#include <bits/stdc++.h>

using namespace std;

long long power(int n, int x) 
{
    int result = 1;
    for (int i = 0; i < x; i++) 
    {
        result *= n;
    }
    return result;
}

void solve() 
{
    int n;
    long long sum = 0;
    int size = 0;
    vector<int> v;
    while (true) 
    {
        cin >> n;
        v.push_back(n);
        size++;
        if (n == 0) 
        {
            break;
        }
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (int i = 0; i < size; i++) 
    {
        sum += 2 * (long long)power(v[i], i + 1);
    }
    if (sum >= 5000000)
    {
        cout << "Too expensive" << '\n';
    }
    else 
    {
        cout << sum << '\n';
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--) 
    {
        solve();
    }
}