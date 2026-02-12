#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long L;
    if (!(cin >> n >> L))
    {
        return 0;
    }

    long long total_word_length = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        total_word_length += s.length();
    }

    if (n == 1)
    {
        if (total_word_length == L)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }
    else
    {
        long long space_needed = L - total_word_length;
        long long gaps = n - 1;

        if (space_needed < gaps)
        {
            cout << "No";
        }
        else
        {
            if (space_needed % gaps == 0)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
    }

    return 0;
}