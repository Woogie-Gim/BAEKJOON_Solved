#include <iostream>
using namespace std;

int sum = 0;

void recursion(int N, int M) {
    if (N == M) {
        sum += 1;
        return;
    }
    if (N > M) {
        sum += 1;
        recursion(N - M, M);
    } else { // N < M
        sum += 1;
        recursion(N, M - N);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    recursion(N, M);
    cout << sum << endl;
    return 0;
}
