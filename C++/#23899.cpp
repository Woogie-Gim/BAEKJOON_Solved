#include <iostream>
#include <algorithm>

using namespace std;

int A[10001];
int B[10001];

int selection_sort(int N) 
{
    if (equal(A, A + N, B)) return 1;

    for (int i = N - 1; i > 0; i--)
    {
        int big = 0;
        for (int j = 0; j <= i; j++)
        {
            if (A[j] > A[big]) big = j;
        }

        if (big != i) 
        {
            int tmp = A[i];
            A[i] = A[big];
            A[big] = tmp;
        }

        if (equal(A, A + N, B)) return 1;
    }
    
    return 0;
}

int main() 
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    cout << selection_sort(N) << endl;

    return 0;
}