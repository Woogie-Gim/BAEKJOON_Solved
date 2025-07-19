#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    if (N % 2 == 0 || M % 2 == 0)
    {
        cout << "A" << '\n';
    }
    else
    {
        cout << "B" << '\n';
    }

    return 0;
}
