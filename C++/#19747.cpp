#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<int> forbidden(n, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        
        int A = a - 1;
        int k = (i - A) % n;
        
        if (k < 0)
        {
            k += n;
        }
        
        forbidden[k] = 1;
    }

    int ans = -1;

    for (int k = 0; k < n; k++)
    {
        if (forbidden[k] == 0)
        {
            ans = k;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}