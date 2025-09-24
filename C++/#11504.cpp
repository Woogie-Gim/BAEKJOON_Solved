#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        string Xs = "";
        string Ys = "";

        for (int i = 0; i < M; i++)
        {
            char c;
            cin >> c;
            Xs.push_back(c);
        }

        for (int i = 0; i < M; i++)
        {
            char c;
            cin >> c;
            Ys.push_back(c);
        }

        vector<int> wheel(N);
        for (int i = 0; i < N; i++)
        {
            cin >> wheel[i];
        }

        int X = stoi(Xs);
        int Y = stoi(Ys);

        int count = 0;

        for (int start = 0; start < N; start++)
        {
            string num = "";
            for (int j = 0; j < M; j++)
            {
                int idx = (start + j) % N;
                num.push_back(char('0' + wheel[idx]));
            }

            int Z = stoi(num);
            if (X <= Z && Z <= Y)
            {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
