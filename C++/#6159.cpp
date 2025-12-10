#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int S;
    cin >> N >> S;

    vector<int> length(N);
    for (int i = 0; i < N; i++)
    {
        cin >> length[i];
    }

    sort(length.begin(), length.end());

    int left = 0;
    int right = N - 1;
    long long answer = 0;

    while (left < right)
    {
        int sum = length[left] + length[right];

        if (sum <= S)
        {
            answer += (long long)(right - left);
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << answer;

    return 0;
}
