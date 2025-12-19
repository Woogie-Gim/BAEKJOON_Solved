#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> digits;
int answer = 0;

void dfs(int value)
{
    if (value > N)
    {
        return;
    }

    if (value > answer)
    {
        answer = value;
    }

    for (int i = 0; i < M; i++)
    {
        dfs(value * 10 + digits[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    digits.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> digits[i];
    }

    for (int i = 0; i < M; i++)
    {
        dfs(digits[i]);
    }

    cout << answer << '\n';
    
    return 0;
}
