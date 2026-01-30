#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int A, B;
    cin >> A >> B;

    int C;
    cin >> C;

    vector<int> D(N);
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }

    sort(D.begin(), D.end(), compare);

    int current_calories = C;
    int current_price = A;
    double max_efficiency = (double)current_calories / current_price;

    for (int i = 0; i < N; i++)
    {
        int next_calories = current_calories + D[i];
        int next_price = current_price + B;
        double next_efficiency = (double)next_calories / next_price;

        if (next_efficiency > max_efficiency)
        {
            max_efficiency = next_efficiency;
            current_calories = next_calories;
            current_price = next_price;
        }
        else
        {
            break;
        }
    }

    cout << (int)max_efficiency;

    return 0;
}