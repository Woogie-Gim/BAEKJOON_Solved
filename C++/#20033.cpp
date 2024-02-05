#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto Check = [&](int mid) -> bool {
        for (int i = 0, t = 0; i < n; i++) {
            if (v[i] >= mid) {
                t++;
            } else {
                t = 0;
            }
            if (t >= mid) {
                return true;
            }
        }
        return false;
    };

    int s = 1, e = 1e6;
    while (s + 1 < e) {
        int mid = s + e >> 1;
        if (Check(mid)) {
            s = mid;
        } else {
            e = mid;
        }
    }

    cout << s << '\n';

    return 0;
}
