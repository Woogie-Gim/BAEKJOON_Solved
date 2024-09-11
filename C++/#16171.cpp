#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

string a, b, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> a >> b;

    int size = a.size();
    for (int i = 0; i < size; i++) 
    {
        if (a[i] >= '0' && a[i] <= '9') continue;
        c.push_back(a[i]);
    }

    if (c.find(b) == string::npos) cout << 0 << '\n';
    else cout << 1 << '\n';
    
    return 0;
}