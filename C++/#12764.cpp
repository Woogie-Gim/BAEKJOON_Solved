#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int n;
vector<pair<int, int> > v;
priority_queue<pair<int, int> > pq;
priority_queue<int> left_seats;
int answer[100001]; 
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int s, e;
    for(int i=0; i<n; i++)
    {
        cin >> s >> e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end());
    
    int seat = 0;
    
    for(int i=0; i<v.size(); i++)
    {
        while(!pq.empty())
        {
            if(-pq.top().first <= v[i].first)
            {
                left_seats.push(-pq.top().second);
                pq.pop();
            }
            else break;
        }
        
        if(left_seats.empty())
        {
            pq.push({-v[i].second, seat});
            answer[seat++]++;
        }
        else
        {
            int tmp_seat = -left_seats.top();
            pq.push({-v[i].second, tmp_seat});
            answer[tmp_seat]++;
            left_seats.pop();
        }
    }
    
    cout << seat << "\n";
    for(int i=0; i<seat; i++)
        cout << answer[i] << " ";    
}