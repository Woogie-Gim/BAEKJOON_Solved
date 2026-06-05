#include <string>
#include <vector>

using namespace std;

int solution(string name) 
{
    int n = name.length();
    int alphabet_move = 0;
    int min_cursor_move = n - 1;
    
    for (int i = 0; i < n; i++) 
    {
        int up_count = name[i] - 'A';
        int down_count = 'Z' - name[i] + 1;
        
        if (up_count < down_count) 
        {
            alphabet_move += up_count;
        }
        else 
        {
            alphabet_move += down_count;
        }
        
        int next_idx = i + 1;
        while (next_idx < n && name[next_idx] == 'A') 
        {
            next_idx++;
        }
        
        int turn_right_first = i + i + (n - next_idx);
        int turn_left_first = (n - next_idx) + (n - next_idx) + i;
        
        if (turn_right_first < min_cursor_move) 
        {
            min_cursor_move = turn_right_first;
        }
        if (turn_left_first < min_cursor_move) 
        {
            min_cursor_move = turn_left_first;
        }
    }
    
    return alphabet_move + min_cursor_move;
}