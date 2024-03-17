#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
 
int field[25][25];
int visited[25][25];
 
int n;
int up_time=0;
 
int nx[] = {0, 1, 0, -1};
int ny[] = {1, 0, -1, 0};
 
pair<int, int> now_shark;
int shark_size = 2;
int eat_cnt = 0;
 
void print_field(int stage, int time)
{
    cout<<stage<<"번째 상황 -> 현재 시간 : "<<up_time <<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout<<field[i][j]<<" ";
        cout<<"\n";
    }
}
void print_visited(int stage)
{
    cout<<stage<<"번째 VISITED : \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout<<visited[i][j]<<" ";
        cout<<"\n";
    }
}
 
void input()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>field[i][j];
            if(field[i][j] == 9) 
            {
                field[i][j] = 0;
                now_shark = {i, j};
            }
        }
    }
}
 
void clear_visited()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) visited[i][j] = 0;
    }
}
 
vector<pair<int, pair<int, int> > > find_food()
{
    vector<pair<int, pair<int, int> > >food_dir;
    
    queue<pair<int, int> > q;
    q.push({now_shark.first, now_shark.second});
    visited[now_shark.first][now_shark.second] = 1;
    
    while(!q.empty())
    {
        int now_x = q.front().first;
        int now_y = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++)
        {
            int dx = now_x + nx[i];
            int dy = now_y + ny[i];
            
            if(0<=dx && dx < n && 0<=dy && dy < n)
            {
                if(visited[dx][dy] != 0) continue;
                if(field[dx][dy] > shark_size) continue;
                else if(field[dx][dy] == shark_size || field[dx][dy] == 0){
                    q.push({dx, dy});
                    visited[dx][dy] = visited[now_x][now_y]+1;
                    continue;
                }
                else if(field[dx][dy] < shark_size){
                    food_dir.push_back({visited[now_x][now_y], {dx, dy}});
                }
            }
        }
    }
    
    return food_dir;
}
 
int eat_food(vector<pair<int, pair<int, int> > > food_dir)
{
    if(food_dir.size() == 0)
    {
        cout<<up_time;
        return 0;
    }
    else if(food_dir.size() == 1)
    {
        up_time += food_dir[0].first;
        eat_cnt++;
        if(eat_cnt == shark_size)
        {
            eat_cnt = 0;
            shark_size++;
        }
        
        field[now_shark.first][now_shark.second] = 0;
        now_shark.first = food_dir[0].second.first;
        now_shark.second = food_dir[0].second.second;
        field[now_shark.first][now_shark.second] = 0;
        return 1;
    }
    else
    {
        sort(food_dir.begin(), food_dir.end());
        
        int min_dir_target = food_dir[0].first;
        int most_top = 100000, most_left = 1000000;
        int idx = 0;
        
        for(int i=0; i<food_dir.size(); i++)
        {
            if(food_dir[i].first == min_dir_target)
            {
                if(food_dir[i].second.first < most_top)
                {
                    most_top = food_dir[i].second.first;
                    most_left = food_dir[i].second.second;
                    idx = i;
                }
                if(food_dir[i].second.first == most_top)
                {
                    if(food_dir[i].second.second < most_left)
                    {
                        most_left = food_dir[i].second.second;
                        idx = i;
                    }
                }
            }
            
        }
        
        up_time += food_dir[idx].first;
        eat_cnt++;
        if(eat_cnt == shark_size)
        {
            eat_cnt = 0;
            shark_size++;
        }
        field[now_shark.first][now_shark.second] = 0;
        now_shark.first = food_dir[idx].second.first;
        now_shark.second = food_dir[idx].second.second;
        field[now_shark.first][now_shark.second] = 0;
        
        return 1;
    }
}
void solve()
{
    input();
    int stage = 1;
    while(1)
    {
        clear_visited();
        vector<pair<int, pair<int, int> > > food_dir = find_food();
        int check = eat_food(food_dir);
        if(check == 0) break;
        food_dir.clear();
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    solve();
    
    return 0;
}