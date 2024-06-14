#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, height;

  cin >> N >> height;

  vector<int>arr(N);
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());
  for (int i = 0; i < N; i++)
    if (arr[i] <= height)
      height += 1;

  cout << height;

  return 0;
}