#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string line;
        getline(cin, line);

        if (!cin)
        {
            break;
        }

        if (line == "#")
        {
            break;
        }

        string digits = "";
        for (int i = 0; i < (int)line.size(); i++)
        {
            if ('0' <= line[i] && line[i] <= '9')
            {
                digits += line[i];
            }
        }

        vector<int> found;
        bool used[10] = { false };

        for (int i = 0; i + 1 < (int)digits.size(); i++)
        {
            if (digits[i] == digits[i + 1])
            {
                int d = digits[i] - '0';
                if (!used[d])
                {
                    used[d] = true;
                    found.push_back(d);
                }
            }
        }

        if (found.empty())
        {
            continue;
        }

        for (int i = 0; i < (int)found.size(); i++)
        {
            if (i > 0)
            {
                cout << " and ";
            }
            cout << found[i] << " " << found[i] << " glued";
        }
        cout << '\n';
    }

    return 0;
}
