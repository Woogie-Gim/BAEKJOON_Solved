#include <iostream>
#include <set>

using namespace std;

int main() 
{
    set<int> s;
    int n, m, num;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s.insert(num);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> num;
        if (s.find(num) == s.end())
            s.insert(num);
        else
            s.erase(num);
    }

    cout << s.size();  
    return 0;
}