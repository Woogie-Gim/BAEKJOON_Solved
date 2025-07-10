#include <iostream>
#include <vector>

using namespace std;

int bubble_sort(vector<int>& A, int N, int K)
{
    int count = 0;

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                count++;
            }

            if (count == K)
            {
                return j;
            }
        }
    }

    return -1;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int result = bubble_sort(A, N, K);

    if (result == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}