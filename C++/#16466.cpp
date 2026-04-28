#include <iostream>
#include <vector>

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

    vector<bool> present(N + 2, false);

    for (int i = 0; i < N; i++)
    {
        int ticket;
        cin >> ticket;
        
        if (ticket <= N)
        {
            present[ticket] = true;
        }
    }

    for (int i = 1; i <= N + 1; i++)
    {
        if (!present[i])
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}