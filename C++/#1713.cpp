#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <int, pair<int, int>> m;

bool cmp1(const pair<int,pair<int,int>>& a, const pair<int, pair<int,int>>& b)
{
    if(a.second.first == b.second.first) return a.first < b.first;
    return a.second.first < b.second.first;
}

bool cmp2(const pair<int,pair<int,int>>& a, const pair<int, pair<int,int>>& b)
{
    if(a.second.second == b.second.second) return a.first < b.first;
    return a.second.second < b.second.second;
}

void insert(int student, int n)
{
    if(m.find(student) != m.end())
    {
        m[student].first++; 
    }
    else
    {
        m[student].first = 1;
        m[student].second = n;
    }
}

void erase(int student, int n)
{
    if(m.find(student) != m.end())
    {
        m[student].first++;
        return;
    }

    vector<pair<int,pair<int,int>>> vec1(m.begin(), m.end());
    sort(vec1.begin(), vec1.end(), cmp1);

    int recommend = vec1[0].second.first, cnt=0;

    for(auto it : vec1)
    {
        if(it.second.first == recommend) cnt++;
    }

    if(cnt == 1)
    {
        m.erase(vec1[0].first);
    }  
    else if(cnt > 1)
    {
        map<int, pair<int,int>> same_r;

        for(auto it : vec1)
        {
            if(recommend == it.second.first)
            {
                same_r[it.first].first = it.second.first;
                same_r[it.first].second = it.second.second;
            }
        }

        vector<pair<int,pair<int,int>>> vec2(same_r.begin(), same_r.end());
        sort(vec2.begin(), vec2.end(), cmp2);
            
        m.erase(vec2[0].first);
    }
      
    insert(student, n);
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int n, r, student;
    
    cin >> n >> r;

    for(int i = 0 ; i < r ; i++)
    {
        cin >> student;

        if(m.size() < n)
        {
            insert(student, i); 
        }
        else if(m.size() == n)
        {
            erase(student, i);
        }
    }

    for(auto it = m.begin() ; it != m.end() ; it++)
    {
        cout << it->first << " ";
    }

    return 0;
}