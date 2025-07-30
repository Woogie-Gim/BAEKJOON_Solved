#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v, n, m;
vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    for (int i = 0; i < n - m + 1; i++)
    {
        cin >> v;
        sort(vec.begin(), vec.begin() + m);
        vec.erase(vec.begin() + v - 1);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    
    return 0;
}