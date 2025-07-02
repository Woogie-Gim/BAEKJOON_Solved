#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    unordered_map<char, int> mp;
    for (char c : a) mp[c]++;
    for (char c : b) mp[c]--;

    int ans = 0;
    
    for (auto [_, v] : mp)
    {
        ans += abs(v);
    }

    cout << ans / 2;

    return 0;
}
