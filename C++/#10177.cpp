#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        int target = 0;
        for (int j = 0; j < n; ++j)
        {
            target += arr[0][j];
        }

        int leftDiagonal = 0;
        int rightDiagonal = 0;
        bool isMagic = true;

        for (int i = 0; i < n; ++i)
        {
            int rowSum = 0;
            int colSum = 0;

            for (int j = 0; j < n; ++j)
            {
                rowSum += arr[i][j];
                colSum += arr[j][i];
            }

            if (rowSum != target || colSum != target)
            {
                isMagic = false;
                break;
            }

            leftDiagonal += arr[i][i];
            rightDiagonal += arr[i][n - 1 - i];
        }

        if (leftDiagonal != target || rightDiagonal != target)
        {
            isMagic = false;
        }

        if (isMagic)
        {
            cout << "Magic square of size " << n << '\n';
        }
        else
        {
            cout << "Not a magic square" << '\n';
        }
    }

    return 0;
}
