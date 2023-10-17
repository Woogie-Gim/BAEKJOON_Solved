#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M, num;
    cin >> N >> M;
    
    vector<int> A(N), B(M), ret;
    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) 
    {
        cin >> B[i];
    }
    
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) 
    {
        if (!binary_search(B.begin(), B.end(), A[i])) 
        {
            ret.push_back(A[i]);
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i : ret) 
    {
        cout << i << ' ';
    }
    return 0;
}