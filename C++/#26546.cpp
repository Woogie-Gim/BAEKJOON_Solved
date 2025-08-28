#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        int i, j;
        cin >> s >> i >> j;

        string result = s.substr(0, i) + s.substr(j);
        cout << result << "\n";
    }

    return 0;
}
