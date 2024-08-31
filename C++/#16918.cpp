#include <iostream>
#include <string>
using namespace std;

int arr[201][201] = {0, };
bool boom[201][201] = {0, };
int R, C, N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void result_print()
{
  for (int i = 0; i < R; i++) 
  {
    for (int j = 0; j < C; j++) 
    {
      if(arr[i][j] >= 0) cout << "O";
      else cout << ".";
    }
    cout << "\n";
  }
}

bool available(int x, int y){ return x >= 0 && y >= 0 && x < R && y < C; }

int main()
{
  cin >> R >> C >> N;
  for (int i = 0; i < R; i++) 
  {
    string s;
    cin >> s;
      
    for (int j = 0; j < C; j++) 
    {
      if(s[j] == '.') arr[i][j] = -1;
      else arr[i][j] = 1;
    }
  }

  int tick = 1;
  while(tick < N)
  {
    for (int i = 0; i < R; i++) 
    {
      for (int j = 0; j < C; j++) 
      {
        if(arr[i][j] >= 0) arr[i][j]--;
        else arr[i][j] = 1;
      }
    }
    tick++;
    if(tick >= N) break;

    for (int i = 0; i < R; i++) 
    {
      for (int j = 0; j < C; j++) 
      {
        if(arr[i][j] == 0) boom[i][j] = true;
        else boom[i][j] = false;
      }
    }
      
    for (int i = 0; i < R; i++) 
    {
      for (int j = 0; j < C; j++) 
      {
        if(!boom[i][j]) continue;
        arr[i][j] = -1;
        for (int k = 0; k < 4; k++) if(available(i+dx[k], j+dy[k])) arr[i+dx[k]][j+dy[k]] = -1;
      }
    }
    tick++;
  }
  result_print();

  return 0;
}