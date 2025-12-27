#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> answer(3), guess(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> answer[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> guess[i];
    }

    bool usedAnswer[3][3] = { false };
    bool usedGuess[3][3] = { false };

    int green = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (answer[i][j] == guess[i][j])
            {
                green++;
                usedAnswer[i][j] = true;
                usedGuess[i][j] = true;
            }
        }
    }

    int cntAnswer[26] = { 0 };
    int cntGuess[26] = { 0 };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!usedAnswer[i][j])
            {
                cntAnswer[answer[i][j] - 'A']++;
            }
            if (!usedGuess[i][j])
            {
                cntGuess[guess[i][j] - 'A']++;
            }
        }
    }

    int yellow = 0;
    for (int c = 0; c < 26; c++)
    {
        yellow += min(cntAnswer[c], cntGuess[c]);
    }

    cout << green << '\n';
    cout << yellow << '\n';

    return 0;
}
