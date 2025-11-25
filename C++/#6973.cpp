#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string encodeWord(string &w, vector<string> &dict, unordered_map<string, int> &pos)
{
    if (w.empty())
    {
        return "";
    }

    unordered_map<string, int>::iterator it = pos.find(w);
    if (it != pos.end())
    {
        int idx = it->second;
        return to_string(idx);
    }
    else
    {
        int idx = (int)dict.size() + 1;
        dict.push_back(w);
        pos[w] = idx;
        return w;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    string line;
    getline(cin, line);

    for (int tc = 0; tc < T; tc++)
    {
        vector<string> lines;

        while (true)
        {
            if (!getline(cin, line))
            {
                break;
            }

            if (line.size() == 0)
            {
                // 세트 사이 구분용 빈 줄
                break;
            }

            lines.push_back(line);
        }

        vector<string> dict;
        unordered_map<string, int> pos;

        for (int i = 0; i < (int)lines.size(); i++)
        {
            string &src = lines[i];
            string word = "";
            string outLine = "";

            for (int j = 0; j < (int)src.size(); j++)
            {
                char c = src[j];
                if (c >= 'a' && c <= 'z')
                {
                    word.push_back(c);
                }
                else if (c == ' ')
                {
                    if (!word.empty())
                    {
                        string enc = encodeWord(word, dict, pos);
                        outLine += enc;
                        word.clear();
                    }
                    outLine.push_back(' ');
                }
                else
                {
                    if (!word.empty())
                    {
                        string enc = encodeWord(word, dict, pos);
                        outLine += enc;
                        word.clear();
                    }
                    outLine.push_back(c);
                }
            }

            if (!word.empty())
            {
                string enc = encodeWord(word, dict, pos);
                outLine += enc;
            }

            cout << outLine << '\n';
        }

        if (tc != T - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
