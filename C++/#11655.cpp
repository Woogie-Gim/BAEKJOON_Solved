#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = s[i];

        if ('a' <= c && c <= 'z')
        {
            c = (char)('a' + (c - 'a' + 13) % 26);
        }
        else if ('A' <= c && c <= 'Z')
        {
            c = (char)('A' + (c - 'A' + 13) % 26);
        }

        s[i] = c;
    }

    cout << s << "\n";
    
    return 0;
}
