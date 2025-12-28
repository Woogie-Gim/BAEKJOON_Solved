#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> answers;

    for (int fghij = 0; fghij <= 11111; fghij++)
    {
        int abcde = fghij * 9;
        if (abcde > 99999)
        {
            continue;
        }

        bool used[10] = { false };

        int temp = fghij;
        for (int i = 0; i < 5; i++)
        {
            used[temp % 10] = true;
            temp /= 10;
        }

        temp = abcde;
        for (int i = 0; i < 5; i++)
        {
            used[temp % 10] = true;
            temp /= 10;
        }

        bool ok = true;
        for (int i = 0; i < 10; i++)
        {
            if (!used[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            answers.push_back({ abcde, fghij });
        }
    }

    sort(answers.begin(), answers.end());

    cout << setw(5) << setfill('0') << answers[N - 1].first << " ";
    cout << setw(5) << setfill('0') << answers[N - 1].second << "\n";

    return 0;
}
