#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int test;
    cin >> test;
    cin.ignore();

    for (int i = 1; i <= test; i++)
    {
        string str;
        getline(cin, str);

        transform(str.begin(), str.end(), str.begin(), ::tolower);

        int arr[26] = { 0 };
        int cnt = 0;
        int len = str.length();

        for (int i = 0; i < len; i++)
        {
            if (isalpha(str[i]))
            {
                cnt = str[i] - 'a';
                arr[cnt]++;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;

        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                cnt1++;
            }
            if (arr[i] == 2)
            {
                cnt2++;
            }
            if (arr[i] >= 3)
            {
                cnt3++;
            }
        }

        if (cnt3 == 26)
        {
            cout << "Case " << i << ": Triple pangram!!!" << endl;
        }
        else if (cnt2 == 26 || cnt2 + cnt3 == 26)
        {
            cout << "Case " << i << ": Double pangram!!" << endl;
        }
        else if (cnt1 == 26)
        {
            cout << "Case " << i << ": Pangram!" << endl;
        }
        else
        {
            cout << "Case " << i << ": Not a pangram" << endl;
        }
    }

    return 0;
}