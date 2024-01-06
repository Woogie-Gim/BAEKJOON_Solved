#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<vector<int>> v(101, vector<int>(101, 0));

    for (int k = 0; k < n; ++k) 
    {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; ++i) 
        {
            for (int j = y; j < y + 10; ++j) 
            {
                v[i][j] = 1;
            }
        }
    }

    int Sum = 0;
    for (int i = 0; i < 101; ++i) 
    {
        for (int j = 0; j < 101; ++j) 
        {
            if (v[i][j] == 1) 
            {
                Sum += 1;
            }
        }
    }

    cout << Sum << "\n";

    return 0;
}
