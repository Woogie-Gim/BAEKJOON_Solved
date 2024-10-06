#include <iostream>

using namespace std;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) 
  {
    int n; cin >> n;

    if (n == 0)
      break;

    int totalBlocks = n * (n + 1) / 2;
    cout << totalBlocks << "\n";
  }

  return 0;
}