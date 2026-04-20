#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string l_str;
    int k, m;
    if (!(cin >> n >> l_str >> k >> m))
    {
        return 0;
    }

    int B = (m + 8) / 9;
    long long BASE = 1000000000LL;

    auto parse = [&](const string& s) {
        vector<long long> res(B, 0);
        int len = s.length();
        for (int i = 0; i < B; i++)
        {
            int end = len - i * 9;
            if (end <= 0) break;
            int start = max(0, end - 9);
            long long val = 0;
            for (int j = start; j < end; j++)
            {
                val = val * 10 + (s[j] - '0');
            }
            res[i] = val;
        }
        return res;
    };

    auto add = [&](vector<long long>& a, const vector<long long>& b) {
        long long carry = 0;
        for (int i = 0; i < B; i++)
        {
            long long sum = a[i] + b[i] + carry;
            if (sum >= BASE)
            {
                a[i] = sum - BASE;
                carry = 1;
            }
            else
            {
                a[i] = sum;
                carry = 0;
            }
        }
    };

    auto mul = [&](const vector<long long>& a, const vector<long long>& b) {
        vector<long long> res(B, 0);
        for (int i = 0; i < B; i++)
        {
            if (a[i] == 0) continue;
            long long carry = 0;
            for (int j = 0; i + j < B; j++)
            {
                long long prod = res[i + j] + a[i] * b[j] + carry;
                res[i + j] = prod % BASE;
                carry = prod / BASE;
            }
        }
        return res;
    };

    auto add_one = [&](vector<long long>& a) {
        long long carry = 1;
        for (int i = 0; i < B; i++)
        {
            long long sum = a[i] + carry;
            if (sum >= BASE)
            {
                a[i] = sum - BASE;
                carry = 1;
            }
            else
            {
                a[i] = sum;
                carry = 0;
                break;
            }
        }
    };

    auto sum_sq_last_m = [&](const vector<long long>& a) {
        int remaining = m;
        long long sum = 0;
        for (int i = 0; i < B; i++)
        {
            long long val = a[i];
            for (int d = 0; d < 9; d++)
            {
                if (remaining == 0) break;
                long long digit = val % 10;
                sum += digit * digit;
                val /= 10;
                remaining--;
            }
            if (remaining == 0) break;
        }
        return sum;
    };

    vector<vector<long long>> coeffs(n + 1);
    for (int i = n; i >= 0; i--)
    {
        string a_str;
        cin >> a_str;
        coeffs[i] = parse(a_str);
    }

    vector<long long> x_val = parse(l_str);

    for (int step = 0; step < k; step++)
    {
        vector<long long> px = coeffs[n];
        for (int i = n - 1; i >= 0; i--)
        {
            px = mul(px, x_val);
            add(px, coeffs[i]);
        }
        cout << sum_sq_last_m(px) << "\n";
        add_one(x_val);
    }

    return 0;
}