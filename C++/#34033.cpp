#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, long long> prices;

    for (int i = 0; i < N; i++)
    {
        string name;
        long long price;
        cin >> name >> price;
        prices[name] = price;
    }

    int count = 0;

    for (int i = 0; i < M; i++)
    {
        string name;
        long long tx_price;
        cin >> name >> tx_price;

        long long original_price = prices[name];

        if (tx_price * 100 > original_price * 105)
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}