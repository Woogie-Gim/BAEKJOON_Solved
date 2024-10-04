#include <iostream>
#include <map>

using namespace std;
 
int n;
string books;
map<string, int> m;
 
int main() 
{
    cin >> n;
 
    for (int i = 0; i < n; i++) 
    {
        cin >> books;
        m[books]++;
    }
    
    int max = 0;  
    string maxB; 
    for (auto iter = m.begin(); iter != m.end(); iter++) 
    {
        if (iter->second > max)
        {
            max = iter->second;
            maxB = iter->first;
        }
        else if (iter->second == max) 
        {
            if (maxB > iter->first) 
            {
                maxB = iter->first;
            }
        }
    }
    cout << maxB;
}