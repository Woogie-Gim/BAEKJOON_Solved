#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string S;
    cin >> S;

    int counts[26] = { 0 };
    int half_len = N / 2;

    for (int i = 0; i < half_len; i++)
    {
        int index = S[i] - 'a';
        counts[index]++;
    }

    for (int i = N - half_len; i < N; i++)
    {
        int index = S[i] - 'a';
        counts[index]++;
    }

    bool possible = true;
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] % 2 != 0)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}