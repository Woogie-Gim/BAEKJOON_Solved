#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        for (int j = 0; j < (int)name.size(); j++)
        {
            if (name[j] == 'S')
            {
                cout << name;
                return 0;
            }
        }
    }

    return 0;
}
