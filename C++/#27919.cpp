#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  string V, ans = "";
    
  cin >> V;
    
  int uc = 0, dp = 0;
    
  for (char i : V)
  {
      if (i == 'U' || i == 'C')
          uc++;
      else
          dp++;      
  }

  if (uc > (dp + 1) / 2)
  {
      ans += 'U';
  }
    
  if (dp > 0)
  {
      ans += "DP";
  }
    
  cout << ans;
    
  return 0;
}