#include <iostream>

using namespace std;

int main()
{
    int N, score, P;
    int rank[100];

    cin >> N >> score >> P;

    for (int i = 0; i < N; i++) 
    {
        cin >> rank[i];
    }

    int cnt = 0;
    
    int my_rank = 1;
    
    for (int i = 0; i < N; i++)
    {
        if (score < rank[i]) my_rank += 1;
        else if (score == rank[i]) my_rank = my_rank;
        else break;
        
        cnt++;
    }


    if (cnt == P) my_rank = -1;
    if (N == 0) my_rank = 1;

    cout << my_rank;

    return 0;
}