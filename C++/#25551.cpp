#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> mask(2), shirt(2), pants(2);
    
    for (int i = 0; i < 2; i++) cin >> mask[i];
    for (int i = 0; i < 2; i++) cin >> shirt[i];
    for (int i = 0; i < 2; i++) cin >> pants[i];

    vector<int> array_1, array_2;

    array_1.push_back(mask[0]);
    array_1.push_back(shirt[1]);
    array_1.push_back(pants[0]);

    array_2.push_back(mask[1]);
    array_2.push_back(shirt[0]);
    array_2.push_back(pants[1]);

    sort(array_1.begin(), array_1.end());
    sort(array_2.begin(), array_2.end());

    vector<int> answer_array;
    
    answer_array.push_back(array_1[0]);
    answer_array.push_back(array_2[0]);
    
    sort(answer_array.begin(), answer_array.end());

    if (answer_array[1] - answer_array[0] != 0 && answer_array[1] - answer_array[0] != 1) 
    {
        cout << answer_array[0] * 2 + 1 << "\n";
    } 
    else 
    {
        cout << answer_array[0] + answer_array[1] << "\n";
    }

    return 0;
}