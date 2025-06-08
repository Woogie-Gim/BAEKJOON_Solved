#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    register int N, K, KR, KC, QR, QC, t1, t2;
    register int dx[8]{ -1, -1, 0, 1, 1, 1, 0, -1 };
    register int dy[8]{ 0, 1, 1, 1, 0, -1, -1, -1 };
    map<pair<int, int>, bool> arr;

    cin >> N >> K >> KR >> KC;
    arr[make_pair(KR, KC)] = false;

    for (register int d = 0, nx, ny; d < 8; ++d)
    {
        nx = KR + dx[d];
        ny = KC + dy[d];

        if (0 < nx && nx <= N && 0 < ny && ny <= N)
        {
            arr[make_pair(nx, ny)] = false;
        }
    }

    for (register int k = 0; k < K; ++k)
    {
        cin >> QR >> QC;

        for (map<pair<int, int>, bool>::iterator it = arr.begin(); it != arr.end(); ++it)
        {
            if (!it->second)
            {
                if (it->first.first == QR)
                {
                    it->second = true;
                }
                else if (it->first.second == QC)
                {
                    it->second = true;
                }
                else
                {
                    t1 = it->first.first - QR;
                    t2 = it->first.second - QC;

                    if (arr.find(make_pair(QR + t1, QC + t1)) != arr.end())
                    {
                        arr[make_pair(QR + t1, QC + t1)] = true;
                    }
                    if (arr.find(make_pair(QR + t1, QC - t1)) != arr.end())
                    {
                        arr[make_pair(QR + t1, QC - t1)] = true;
                    }
                    if (arr.find(make_pair(QR - t1, QC + t1)) != arr.end())
                    {
                        arr[make_pair(QR - t1, QC + t1)] = true;
                    }
                    if (arr.find(make_pair(QR - t1, QC - t1)) != arr.end())
                    {
                        arr[make_pair(QR - t1, QC - t1)] = true;
                    }
                    if (arr.find(make_pair(QR + t2, QC + t2)) != arr.end())
                    {
                        arr[make_pair(QR + t2, QC + t2)] = true;
                    }
                    if (arr.find(make_pair(QR + t2, QC - t2)) != arr.end())
                    {
                        arr[make_pair(QR + t2, QC - t2)] = true;
                    }
                    if (arr.find(make_pair(QR - t2, QC + t2)) != arr.end())
                    {
                        arr[make_pair(QR - t2, QC + t2)] = true;
                    }
                    if (arr.find(make_pair(QR - t2, QC - t2)) != arr.end())
                    {
                        arr[make_pair(QR - t2, QC - t2)] = true;
                    }
                }
            }
        }
    }

    register int check1 = 0, check2 = 0;

    for (map<pair<int, int>, bool>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (it->first.first == KR && it->first.second == KC)
        {
            if (it->second)
            {
                check1 = 1;
            }
        }
        else
        {
            if (it->second)
            {
                ++check2;
            }
        }
    }

    if (check1)
    {
        if (check2 == (arr.size() - 1))
        {
            cout << "CHECKMATE";
        }
        else
        {
            cout << "CHECK";
        }
    }
    else
    {
        if (check2 == (arr.size() - 1))
        {
            cout << "STALEMATE";
        }
        else
        {
            cout << "NONE";
        }
    }

    return 0;
}
