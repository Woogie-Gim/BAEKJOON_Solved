#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> order;
    unordered_map<string, long long> countMap;
    long long total = 0;

    string line;
    while (getline(cin, line))
    {
        if (line == "0")
        {
            break;
        }
        if (countMap.find(line) == countMap.end())
        {
            order.push_back(line);
        }
        countMap[line] += 1;
        total += 1;
    }

    for (size_t i = 0; i < order.size(); ++i)
    {
        cout << order[i] << ": " << countMap[order[i]] << '\n';
    }
    cout << "Grand Total: " << total << '\n';

    return 0;
}
