#include <iostream>
#include <map>

using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long findResult(long long n)
{
    if (m[n] != 0) return m[n];

    return m[n] = findResult(n / P) + findResult(n / Q);
}

void solution() 
{
    m[0] = 1;
    cout << findResult(N);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;

    solution();

    return 0;
}