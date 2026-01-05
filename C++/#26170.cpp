#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int H = 5;
    const int W = 5;

    int board[H][W];

    unsigned int blockedStart = 0;
    unsigned int appleStart = 0;
    int initialAppleCount = 0;

    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            cin >> board[r][c];
            int idx = r * W + c;

            if (board[r][c] == -1)
            {
                blockedStart |= (1u << idx);
            }
            else if (board[r][c] == 1)
            {
                appleStart |= (1u << idx);
                initialAppleCount++;
            }
        }
    }

    int sr, sc;
    cin >> sr >> sc;

    int startPos = sr * W + sc;

    blockedStart &= ~(1u << startPos);
    appleStart &= ~(1u << startPos);

    struct Node
    {
        unsigned int blocked;
        unsigned int apples;
        int pos;
        int dist;
    };

    auto makeKey = [&](unsigned int blocked, unsigned int apples, int pos) -> unsigned long long
    {
        unsigned long long key = 0;
        key |= (unsigned long long)blocked;
        key |= ((unsigned long long)apples << 25);
        key |= ((unsigned long long)pos << 50);
        return key;
    };

    queue<Node> q;
    unordered_map<unsigned long long, int> dist;

    unsigned long long startKey = makeKey(blockedStart, appleStart, startPos);
    dist[startKey] = 0;
    q.push({ blockedStart, appleStart, startPos, 0 });

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    int answer = -1;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        int eaten = initialAppleCount - __builtin_popcount((unsigned int)cur.apples);
        if (eaten >= 3)
        {
            answer = cur.dist;
            break;
        }

        int r = cur.pos / W;
        int c = cur.pos % W;

        for (int dir = 0; dir < 4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
            {
                continue;
            }

            int npos = nr * W + nc;

            if (cur.blocked & (1u << npos))
            {
                continue;
            }

            unsigned int nextBlocked = cur.blocked | (1u << cur.pos);
            unsigned int nextApples = cur.apples;

            if (nextApples & (1u << npos))
            {
                nextApples &= ~(1u << npos);
            }

            unsigned long long key = makeKey(nextBlocked, nextApples, npos);

            if (dist.find(key) != dist.end())
            {
                continue;
            }

            dist[key] = cur.dist + 1;
            q.push({ nextBlocked, nextApples, npos, cur.dist + 1 });
        }
    }

    cout << answer << '\n';
    
    return 0;
}
