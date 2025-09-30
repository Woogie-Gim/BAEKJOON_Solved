#include <iostream>
#include <vector>
using namespace std;

struct Card
{
    int owner;
    int value;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<Card> deck;
    deck.reserve(N * K);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int v;
            cin >> v;
            deck.push_back({i + 1, v});
        }
    }

    int idx = 0;
    
    while (deck.size() > 1)
    {
        int step = deck[idx].value;
        deck.erase(deck.begin() + idx);

        if (deck.empty())
        {
            break;
        }
        idx = (idx + step - 1) % deck.size();
    }

    cout << deck[0].owner << " " << deck[0].value << "\n";
    
    return 0;
}
