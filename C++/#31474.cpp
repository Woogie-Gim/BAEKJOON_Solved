#include <iostream>

using namespace std;

long long int N, result = 1;

int main() 
{
  cin >> N;

  for (int i = N; i > 0; i -= 2) 
  { 
    result *= (i * (i - 1)) / 2; 

    result /= (i/2);
  }

  cout << result << "\n";

  return 0;
}