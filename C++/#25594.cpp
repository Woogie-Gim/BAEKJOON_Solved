#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int nxt[26];
    int term;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            nxt[i] = -1;
        }
        term = -1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 26개 코드표
    const string code[26] =
    {
        "aespa",    // a
        "baekjoon", // b
        "cau",      // c
        "debug",    // d
        "edge",     // e
        "firefox",  // f
        "golang",   // g
        "haegang",  // h
        "iu",       // i
        "java",     // j
        "kotlin",   // k
        "lol",      // l
        "mips",     // m
        "null",     // n
        "os",       // o
        "python",   // p
        "query",    // q
        "roka",     // r
        "solvedac", // s
        "tod",      // t
        "unix",     // u
        "virus",    // v
        "whale",    // w
        "xcode",    // x
        "yahoo",    // y
        "zebra"     // z
    };

    string S;
    if (!(cin >> S))
    {
        return 0;
    }

    vector<Node> trie;
    trie.emplace_back();

    auto add = [&](const string &w, int letter)
    {
        int cur = 0;
        for (char ch : w)
        {
            int c = ch - 'a';
            if (trie[cur].nxt[c] == -1)
            {
                trie[cur].nxt[c] = (int)trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[c];
        }
        trie[cur].term = letter;
    };

    for (int i = 0; i < 26; i++)
    {
        add(code[i], i);
    }

    string ans;
    ans.reserve(S.size() / 2); 

    int cur = 0;
    
    for (char ch : S)
    {
        int c = ch - 'a';
        if (c < 0 || c >= 26 || trie[cur].nxt[c] == -1)
        {
            cout << "ERROR!\n";
            return 0;
        }
        cur = trie[cur].nxt[c];

        if (trie[cur].term != -1)
        {
            ans.push_back(char('a' + trie[cur].term));
            cur = 0;
        }
    }

    if (cur != 0)
    {
        cout << "ERROR!\n";
        return 0;
    }

    cout << "It's HG!\n";
    cout << ans << "\n";
    
    return 0;
}
