#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Monitor 
{
    int width;
    int depth;
    int index;
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Monitor> monitors(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> monitors[i].width >> monitors[i].depth;
        monitors[i].index = i + 1;
    }

    stable_sort(monitors.begin(), monitors.end(), [](const Monitor &a, const Monitor &b) 
    {
        return a.width * a.width + a.depth * a.depth > b.width * b.width + b.depth * b.depth;
    });

    for (size_t i = 0; i < monitors.size(); i++) 
    {
        cout << monitors[i].index << '\n';
    }

    return 0;
}