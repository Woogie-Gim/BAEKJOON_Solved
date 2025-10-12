#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    unordered_set<string> seen;
    seen.reserve(n * 2);

    unordered_map<string, int> course_cnt; 
    course_cnt.reserve(n * 2);

    for (int i = 0; i < n; i++)
    {
        string first, last, course;
        cin >> first >> last >> course;

        string key = first;
        key.push_back(' ');
        key += last;
        key.push_back('|');
        key += course;

        if (seen.insert(key).second)
        {
            course_cnt[course]++;
        }
    }

    vector<string> courses;
    courses.reserve(course_cnt.size());
    for (auto &p : course_cnt)
    {
        courses.push_back(p.first);
    }
    sort(courses.begin(), courses.end());

    for (const string &c : courses)
    {
        cout << c << " " << course_cnt[c] << "\n";
    }

    return 0;
}
