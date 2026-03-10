#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    string names[125];
    int scores[125];
    bool present[125];

    for (int i = 0; i < 125; i++)
    {
        scores[i] = 0;
        present[i] = false;
    }

    for (int i = 0; i < N; i++)
    {
        int id;
        cin >> id;

        string name;
        getline(cin, name);

        int start = 0;
        while (start < (int)name.length() && name[start] == ' ')
        {
            start++;
        }
        name = name.substr(start);

        names[id] = name;
        present[id] = true;
    }

    int A;
    cin >> A;

    for (int i = 0; i < A; i++)
    {
        int id;
        char code;
        cin >> id >> code;

        if (code == 'S')
        {
            scores[id] += 10;
        }
        else if (code == 'Q')
        {
            scores[id] += 5;
        }
        else if (code == 'A')
        {
            scores[id] += 7;
        }
        else if (code == 'L')
        {
            scores[id] -= 8;
        }
        else if (code == 'F')
        {
            scores[id] += 4;
        }
        else if (code == 'D')
        {
            scores[id] -= 5;
        }
        else if (code == 'E')
        {
            scores[id] -= 10;
        }
    }

    int max_score = -1000000;
    int min_score = 1000000;

    for (int i = 1; i <= 120; i++)
    {
        if (present[i])
        {
            if (scores[i] > max_score)
            {
                max_score = scores[i];
            }
            if (scores[i] < min_score)
            {
                min_score = scores[i];
            }
        }
    }

    cout << max_score;
    for (int i = 1; i <= 120; i++)
    {
        if (present[i] && scores[i] == max_score)
        {
            cout << " " << names[i];
        }
    }
    cout << "\n";

    cout << min_score;
    for (int i = 1; i <= 120; i++)
    {
        if (present[i] && scores[i] == min_score)
        {
            cout << " " << names[i];
        }
    }
    cout << "\n";

    return 0;
}