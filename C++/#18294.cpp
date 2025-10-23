#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> count;
    count.reserve(n * 2);

    std::string s;
    std::string max_species;
    int max_count = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        int c = ++count[s];
        if (c > max_count)
        {
            max_count = c;
            max_species = s;
        }
    }

    if (max_count > n - max_count)
    {
        std::cout << max_species << '\n';
    }
    else
    {
        std::cout << "NONE\n";
    }

    return 0;
}
