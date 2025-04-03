#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;

bool Check()
{
    for (size_t i = 0; i < v.size(); i++) 
    {
        if (v[i] == 0)
        {
            return false;
        }
    }
    if (v.front() < 0 || v.back() > 0) 
    {
        return false;
    }
    for (size_t i = 0; i < v.size() - 1; i++) 
    {
        if ((v[i] > 0 && v[i + 1] > 0) || (v[i] < 0 && v[i + 1] < 0)) 
        {
            if (v[i] != v[i + 1])
            {
                return false;
            }
        }
    }
    
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string X;
    cin >> X;
    
    for (size_t i = 0; i < X.size() - 1; i++) 
    {
        v.push_back(X[i + 1] - X[i]);
    }
    cout << (Check() ? "ALPSOO" : "NON ALPSOO") << "\n";
    
    return 0;
}