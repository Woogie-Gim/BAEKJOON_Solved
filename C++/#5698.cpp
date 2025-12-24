#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string line;
        getline(cin, line);

        if (line == "*")
        {
            break;
        }

        stringstream ss(line);
        string word;

        ss >> word;
        char startChar = tolower(word[0]);

        bool isTautogram = true;

        while (ss >> word)
        {
            if (tolower(word[0]) != startChar)
            {
                isTautogram = false;
                break;
            }
        }

        if (isTautogram)
        {
            cout << "Y\n";
        }
        else
        {
            cout << "N\n";
        }
    }

    return 0;
}
