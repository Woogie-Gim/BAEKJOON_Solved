#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> qsort(int a, int b, int c, int d)
{
    vector<int> arr = { a, b, c, d };

    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }

    return arr;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> sorted = qsort(a, b, c, d);

    cout << sorted[0] << " " << sorted[2] << " " << sorted[1] << " " << sorted[3] << endl;

    return 0;
}
