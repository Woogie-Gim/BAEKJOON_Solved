#include <iostream>

#define MAX 1000001

using namespace std;

int n, k, cnt, a[100], b[100], c[100], ta, tb, tc, ans = 3 * MAX, aa = MAX, ab = MAX, ac = MAX;

int main() 
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int l = 0; l < n; l++) 
            {
                ta = a[i];
                tb = b[j];
                tc = c[l];
                cnt = 0;

                for (int t = 0; t < n; t++) 
                {
                    if (ta >= a[t] && tb >= b[t] && tc >= c[t]) 
                    {
                        cnt++;
                    }
                }

                if (cnt >= k && ans >= cnt && ta + tb + tc < aa + ab + ac) 
                {
                    ans = cnt;
                    aa = ta;
                    ab = tb;
                    ac = tc;
                }
            }
        }
    }

    cout << aa + ab + ac << '\n';

    return 0;
}