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

    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        int p = x & 1;

        if (!st.empty() && st.back() == p)
        {
            st.pop_back();
        }
        else
        {
            st.push_back(p);
        }
    }

    cout << (int)st.size() << '\n';
    
    return 0;
}
