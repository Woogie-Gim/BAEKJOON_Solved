#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    vector<int> prefixTwo(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        prefixTwo[i] = prefixTwo[i - 1] + (a[i] == 2 ? 1 : 0);
    }

    vector<int> suffixOne(N + 2, 0);
    for (int i = N; i >= 1; i--)
    {
        suffixOne[i] = suffixOne[i + 1] + (a[i] == 1 ? 1 : 0);
    }

    int answer = N;

    for (int t = 0; t <= N; t++)
    {
        int leftChange = prefixTwo[t];
        int rightChange = suffixOne[t + 1]; 
        int total = leftChange + rightChange;

        if (total < answer)
        {
            answer = total;
        }
    }

    cout << answer << '\n';
    
    return 0;
}
