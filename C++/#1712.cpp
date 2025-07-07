#include <iostream>

using namespace std;

int main()
{
    int a, b, c,ans;

    cin >> a >> b >> c;

    if (b >= c)
    {
        cout << "-1"; 
    }
    else 
    {
        ans = a / (c - b) + 1;
        cout << ans;
    }

}