#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    array<int, 5> a;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    auto print = [&]()
    {
        for (int i = 0; i < 5; i++)
        {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    };

    while (true)
    {
        bool sorted = true;
        for (int i = 0; i < 5; i++)
        {
            if (a[i] != i + 1)
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                print();
            }
        }
    }

    return 0;
}
