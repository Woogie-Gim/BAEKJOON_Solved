#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    array<char, 256> trans;
    trans.fill(0);

    for (size_t i = 1; i < keys.size(); i++)
    {
        trans[static_cast<unsigned char>(keys[i])] = keys[i - 1];
    }
    trans[' '] = ' ';

    string line;
    while (getline(cin, line))
    {
        for (char c : line)
        {
            unsigned char uc = static_cast<unsigned char>(c);
            if (trans[uc] != 0)
            {
                cout << trans[uc];
            }
            else
            {
                cout << c;
            }
        }
        cout << '\n';
    }

    return 0;
}
