#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string line;
    getline(cin, line);

    for (int i = 0; i < N; i++)
    {
        getline(cin, line);

        if (line.size() > 0 && line[0] >= 'a' && line[0] <= 'z')
        {
            line[0] = char(line[0] - 'a' + 'A');
        }

        cout << line << '\n';
    }

    return 0;
}
