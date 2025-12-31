#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string s;
        getline(cin, s);

        for (char &c : s)
        {
            if ('A' <= c && c <= 'Z')
            {
                c = c - 'A' + 'a';
            }
        }

        bool ok = true;
        int l = 0;
        int r = (int)s.size() - 1;

        while (l < r)
        {
            if (s[l] != s[r])
            {
                ok = false;
                break;
            }
            l++;
            r--;
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
