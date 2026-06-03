#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<pair<int, int>> move_to_origin(vector<pair<int, int>> block) 
{
    int min_x = block[0].first;
    int min_y = block[0].second;
    
    for (int i = 1; i < block.size(); i++) 
    {
        if (block[i].first < min_x) min_x = block[i].first;
        if (block[i].second < min_y) min_y = block[i].second;
    }
    
    for (int i = 0; i < block.size(); i++) 
    {
        block[i].first -= min_x;
        block[i].second -= min_y;
    }
    
    sort(block.begin(), block.end());
    return block;
}

vector<pair<int, int>> rotate_block(vector<pair<int, int>> block) 
{
    for (int i = 0; i < block.size(); i++) 
    {
        int temp = block[i].first;
        block[i].first = -block[i].second;
        block[i].second = temp;
    }
    return move_to_origin(block);
}

vector<pair<int, int>> get_block_bfs(int sx, int sy, int target_val, int n, vector<vector<int>>& board, vector<vector<bool>>& visited) 
{
    vector<pair<int, int>> block;
    queue<pair<int, int>> q;
    
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    
    while (!q.empty()) 
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        block.push_back(make_pair(cx, cy));
        
        for (int i = 0; i < 4; i++) 
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) 
            {
                if (!visited[nx][ny] && board[nx][ny] == target_val) 
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return move_to_origin(block);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    int n = game_board.size();
    int answer = 0;
    
    vector<vector<bool>> visited_board(n, vector<bool>(n, false));
    vector<vector<bool>> visited_table(n, vector<bool>(n, false));
    
    vector<vector<pair<int, int>>> empty_spaces;
    vector<vector<pair<int, int>>> puzzle_blocks;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (game_board[i][j] == 0 && !visited_board[i][j]) 
            {
                empty_spaces.push_back(get_block_bfs(i, j, 0, n, game_board, visited_board));
            }
            if (table[i][j] == 1 && !visited_table[i][j]) 
            {
                puzzle_blocks.push_back(get_block_bfs(i, j, 1, n, table, visited_table));
            }
        }
    }
    
    vector<bool> space_used(empty_spaces.size(), false);
    vector<bool> block_used(puzzle_blocks.size(), false);
    
    for (int i = 0; i < empty_spaces.size(); i++) 
    {
        for (int j = 0; j < puzzle_blocks.size(); j++) 
        {
            if (block_used[j]) continue;
            if (empty_spaces[i].size() != puzzle_blocks[j].size()) continue;
            
            bool match = false;
            vector<pair<int, int>> curr_block = puzzle_blocks[j];
            
            for (int rot = 0; rot < 4; rot++) 
            {
                if (empty_spaces[i] == curr_block) 
                {
                    match = true;
                    break;
                }
                curr_block = rotate_block(curr_block);
            }
            
            if (match) 
            {
                answer += empty_spaces[i].size();
                block_used[j] = true;
                space_used[i] = true;
                break;
            }
        }
    }
    
    return answer;
}