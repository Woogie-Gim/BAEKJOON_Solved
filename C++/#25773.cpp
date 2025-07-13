#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string number_maximization(const string& number)
{
    vector<char> number_list(number.begin(), number.end());

    sort(number_list.begin(), number_list.end(), greater<char>());

    return string(number_list.begin(), number_list.end());
}

int main()
{
    string number;

    cin >> number;

    cout << number_maximization(number) << "\n";

    return 0;
}
