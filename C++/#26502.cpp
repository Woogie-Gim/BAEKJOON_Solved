#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<char, char> mp = 
  {
    {'a', 'e'}, {'e', 'i'}, {'i', 'o'}, {'o', 'u'}, {'u', 'y'}, {'y', 'a'},
    {'A', 'E'}, {'E', 'I'}, {'I', 'O'}, {'O', 'U'}, {'U', 'Y'}, {'Y', 'A'}
  };

  int n; 
  cin >> n;
  cin.ignore();

  while (n--) 
  {
    string s; 
    getline(cin, s);

    for (auto &c : s) 
    {
      cout << (mp.find(c) != mp.end() ? mp[c] : c);
    }
    cout << "\n";
  }

  return 0;
}