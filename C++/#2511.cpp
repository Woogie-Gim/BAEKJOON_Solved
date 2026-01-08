#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a(10), b(10);

    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }

    int scoreA = 0;
    int scoreB = 0;
    char lastWinner = 'D';

    for (int i = 0; i < 10; i++)
    {
        if (a[i] > b[i])
        {
            scoreA += 3;
            lastWinner = 'A';
        }
        else if (a[i] < b[i])
        {
            scoreB += 3;
            lastWinner = 'B';
        }
        else
        {
            scoreA += 1;
            scoreB += 1;
        }
    }

    cout << scoreA << " " << scoreB << '\n';

    if (scoreA > scoreB)
    {
        cout << "A\n";
    }
    else if (scoreA < scoreB)
    {
        cout << "B\n";
    }
    else
    {
        cout << lastWinner << '\n';
    }

    return 0;
}
