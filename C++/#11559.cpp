#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int result = 0;
int step;
char alph;
bool flag = false;
queue<pair<int, int>> q;
vector<vector<char>> graph;
vector<vector<int>> visit;
vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1}; 
vector<int> color = {0, 0, 0, 0, 0};
vector<pair<int, int>> p;
void PuPu();
int select_color(int x, int y);
void print_ary();
int main()
{
    graph.resize(12, vector<char>(6, 0));
    visit.resize(12, vector<int>(6, 0));
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> graph[i][j];
        }
    }
    while (1)
    {
        flag = false;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (graph[i][j] != '.' && visit[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                    PuPu();
                }
            }
        }
        visit.assign(12, vector<int>(6, 0));
        for (int k = 0; k < p.size(); k++)
        {
            int ax = p[k].first;
            int ay = p[k].second;
            graph[ax][ay] = '.';
        }
        p.clear();
        for (int i = 0; i < 6; i++) 
        {
            queue<char> queue;
            for (int j = 11; j >= 0; j--)
                if (graph[j][i] != '.') queue.push(graph[j][i]);
            for (int j = 11; j >= 0; j--) {
                if (queue.empty()) {
                    graph[j][i] = '.';
                    continue;
                }
                graph[j][i] = queue.front();
                queue.pop();
            }
        }
        if (flag == true)
        {
            result++;
        }
        if (flag == false)
            break;
    }
    cout << result;
}
int select_color(int x, int y)
{
    switch (graph[x][y])
    {
    case 'R':
        return 0;
    case 'G':
        return 1;
        break;
    case 'B':
        return 2;
    case 'P':
        return 3;
    case 'Y':
        return 4;
    }
}
void PuPu()
{
    while (!q.empty())
    {
        int mx = q.front().first;
        int my = q.front().second;
        alph = graph[mx][my];
        step = select_color(mx, my);
        q.pop();
        if (visit[mx][my] == 1)
        {
            continue;
        }
        color[step]++;
        p.push_back(make_pair(mx, my));
        visit[mx][my] = 1;
        for (int i = 0; i < 4; i++)
        {
            int fx = mx + x[i];
            int fy = my + y[i];
            if (fx < 0 || fx >= 12 || fy < 0 || fy >= 12 || graph[fx][fy] != alph || visit[fx][fy] == 1)
            {
                continue;
            }
            q.push(make_pair(fx, fy));
        }
    }
    if (color[step] < 4)
    {
        for (int i = 0; i < color[step]; i++)
        {
            p.pop_back();
        }
        color[step] = 0;
    }
    if (color[step] >= 4)
    {
        flag = true;
        color[step] = 0;
    }
}
void print_ary()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}