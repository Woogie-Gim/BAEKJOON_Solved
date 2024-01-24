#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    if (n == 0 || n == 1) 
    {
        cout << 0 << "\n";
    } 
    else 
    {
        vector<int> prime(n + 1, 1);
        vector<int> num;

        for (int i = 2; i <= n; ++i) 
        {
            if (prime[i] == 1) 
            {
                num.push_back(i);

                for (int j = i * 2; j <= n; j += i) 
                {
                    prime[j] = 0;
                }
            }
        }

        int temp = 0, cnt = 0;
        int high = 0, low = 0;

        while (true) 
        {
            if (temp >= n || high == num.size()) 
            {
                temp -= num[low];
                low += 1;
            } 
            else if (temp < n) 
            {
                temp += num[high];
                high += 1;
            }

            if (temp == n) 
            {
                cnt += 1;
            }

            if (low == num.size()) 
            {
                break;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
