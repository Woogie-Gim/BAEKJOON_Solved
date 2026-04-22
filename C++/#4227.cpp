#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    while (getline(cin, line))
    {
        if (line == "()")
        {
            break;
        }
        if (line.empty())
        {
            continue;
        }

        int idx = 0;

        auto skip_ws = [&]()
        {
            while (idx < line.length() && isspace(line[idx]))
            {
                idx++;
            }
        };

        auto parse = [&](auto& self) -> double
        {
            skip_ws();
            if (idx >= line.length())
            {
                return 0;
            }

            if (line[idx] == '(')
            {
                idx++;
                skip_ws();

                size_t len;
                double p = stod(line.substr(idx), &len);
                idx += len;

                double e1 = self(self);
                double e2 = self(self);

                skip_ws();
                if (idx < line.length() && line[idx] == ')')
                {
                    idx++;
                }

                return e1 + e2 * (2.0 * p - 1.0);
            }
            else
            {
                size_t len;
                double val = stod(line.substr(idx), &len);
                idx += len;
                return val;
            }
        };

        cout << fixed << setprecision(2) << parse(parse) << "\n";
    }

    return 0;
}