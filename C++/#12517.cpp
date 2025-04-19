#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int testCase;
    cin >> testCase;

    string s;
    
    for (int i = 1; i <= testCase && cin >> s; ++i) 
    {
        char lastChar = s.back();
        string ruler;

        if (lastChar == 'y')
        {
            ruler = "nobody";
        } 
        else if (lastChar == 'a' || lastChar == 'e' || lastChar == 'i' ||
                   lastChar == 'o' || lastChar == 'u')
        {
            ruler = "a queen";
        } 
        else
        {
            ruler = "a king";
        }

        cout << "Case #" << i << ": " << s << " is ruled by " << ruler << "." << "\n";
    }

    return 0;
}
