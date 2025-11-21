#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    int answer = 0;

    for (char c = 'a'; c <= 'z'; c++)
    {
        int count_c = 0;

        for (int i = 0; i < N; i++)
        {
            if (S[i] == c || T[i] == c)
            {
                count_c++;
            }
        }

        if (count_c > answer)
        {
            answer = count_c;
        }
    }

    cout << answer;

    return 0;
}
