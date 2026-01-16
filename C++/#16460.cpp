#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string premiumName;
    string pref;
    int maxDist;
    cin >> premiumName >> pref >> maxDist;

    int n;
    cin >> n;

    vector<string> candidates;
    candidates.reserve(n);

    for (int i = 0; i < n; i++)
    {
        string name;
        string gender;
        int dist;
        cin >> name >> gender >> dist;

        int genderOk = 0;
        if (pref == "F")
        {
            if (gender == "F") genderOk = 1;
        }
        else if (pref == "M")
        {
            if (gender == "M") genderOk = 1;
        }
        else
        {
            if (gender == "F" || gender == "M") genderOk = 1;
        }

        if (genderOk && dist <= maxDist)
        {
            candidates.push_back(name);
        }
    }

    if (candidates.size() == 0)
    {
        cout << "No one yet\n";
        return 0;
    }

    sort(candidates.begin(), candidates.end());

    for (int i = 0; i < (int)candidates.size(); i++)
    {
        cout << candidates[i] << '\n';
    }

    return 0;
}
