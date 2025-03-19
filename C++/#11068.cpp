#include <iostream>
#include <string>

using namespace std;

const int MIN = 2;
const int MAX = 64;

bool isPalindrome(int N) 
{
    for (int b = MIN; b <= MAX; b++) 
    {
        int num = N;
        string s;

        while (num) 
        {
            s.push_back((num % b) + '0'); 
            num /= b;
        }

        string reverseS(s.rbegin(), s.rend());
        if (s == reverseS) 
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;
        cout << isPalindrome(N) << "\n";
    }

    return 0;
}