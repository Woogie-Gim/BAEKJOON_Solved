#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c, cnt = 0, i, j, t, f = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> c;

        vector<int> v;

        for (j = 0; j < c; j++)
        {
            cin >> t;
            if (t % 2 != 0) t++;
            v.push_back(t);
        }

        t = v[0];
        for (j = 1; j < c; j++)
            if (t != v[j])
                f = 1;
        
        if (f == 1) 
        {
            while(1)
            {
                vector<int> tmp;

                tmp.push_back(v[c - 1] / 2);
                for (j = 0; j < c - 1; j++)
                    tmp.push_back(v[j] / 2);

                for (j = 0; j < c; j++)
                    tmp[j] += v[j] / 2;

                for (j = 0; j < c; j++)
                {
                    if (tmp[j] % 2 != 0)
                    {
                        tmp[j]++;
                        f = 1;
                    }
                }

                if (f == 1) cnt++;
                f = 0;

                t = tmp[0];
                for (j = 1; j < c; j++)
                    if (t != tmp[j])
                        f = 1;

                if (f == 0) break;
                v = tmp;
            }
        }

        cout << cnt << endl;
        cnt = 0, f = 0;
    }
}
