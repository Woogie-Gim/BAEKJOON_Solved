
#include <iostream>
#include <string>
#include <vector>  
#include <algorithm>
 
using namespace std;
 
int main() 
{
 
    string str,str1;

    int k = 1;
 
    while(true)
    {
        cin >> str >> str1;
        if(str == "END" && str1 == "END")
        {
            break;
        }
 
        vector<char> vec;
        vector<char> v;
 
        for(int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            vec.push_back(c);
        }
 
        for(int j = 0; j < str1.length(); j++)
        {
            char ch = str1[j];
            v.push_back(ch);
        }
        
        sort(vec.begin(), vec.end());
        sort(v.begin(), v.end());
        
        int cnt = 0;
 
        if(vec.size() != v.size())
        {
            cout << "Case " << k << ": different\n";
        }
        else
        {
            for(int i = 0; i < vec.size(); i++)
            {
                if(vec[i] == v[i])
                {
                    cnt++;
                }
            }
            if(cnt == vec.size())
            {
                cout << "Case " << k << ": same\n";
            }
            else
            {
                cout << "Case " << k << ": different\n";
            }
        }
        
        k++;
    }
    
    return 0;
}