#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int G, C, E;
        cin >> G >> C >> E;

        int per;
        if (G == 1)
        {
            per = 1;
        }
        else if (G == 2)
        {
            per = 3;
        }
        else
        {
            per = 5;
        }

        int need = E - C;
        if (need < 0)
        {
            need = 0;
        }

        cout << need * per << "\n";
    }

    return 0;
}
