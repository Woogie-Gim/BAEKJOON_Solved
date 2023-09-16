#include <iostream>
using namespace std;

int main()
{
    int asc[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int des[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };

    int arr[8];

    for (int x = 0; x < 8; x++)
    {
        int a;
        cin >> a;
        arr[x] = a;
    }

    bool isAscending = true;
    bool isDescending = true;

    for (int x = 0; x < 8; x++)
    {
        if (arr[x] != asc[x])
        {
            isAscending = false;
        }
        if (arr[x] != des[x])
        {
            isDescending = false;
        }
    }

    if (isAscending)
    {
        cout << "ascending";
    }
    else if (isDescending)
    {
        cout << "descending";
    }
    else
    {
        cout << "mixed";
    }

    return 0;
}
