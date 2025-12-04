#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    long long modValue = 1000000007LL;

    for (int tc = 1; tc <= T; tc++)
    {
        string word;
        cin >> word;
        int n = (int)word.size();

        long long answer = 1;

        for (int i = 0; i < n; i++)
        {
            int choices = 1;

            if (i > 0 && word[i - 1] != word[i])
            {
                choices++;
            }

            if (i < n - 1)
            {
                if (word[i + 1] != word[i])
                {
                    if (i == 0 || word[i + 1] != word[i - 1])
                    {
                        choices++;
                    }
                }
            }

            answer = (answer * (long long)choices) % modValue;
        }

        cout << "Case #" << tc << ": " << answer << "\n";
    }

    return 0;
}
