#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    int countEW = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (s[i] == 'E' && s[i + 1] == 'W')
        {
            countEW++;
        }
    }

    cout << countEW << '\n';
    
    return 0;
}
