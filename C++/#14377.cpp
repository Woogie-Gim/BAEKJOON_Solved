#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;

        vector<int> count(2505, 0);
        int total_inputs = (2 * N - 1) * N;

        for (int i = 0; i < total_inputs; i++)
        {
            int h;
            cin >> h;
            count[h]++;
        }

        cout << "Case #" << t << ":";
        
        for (int i = 1; i <= 2500; i++)
        {
            if (count[i] % 2 != 0)
            {
                cout << " " << i;
            }
        }
        cout << "\n";
    }

    return 0;
}