#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n) 
{
    if (n <= 1) 
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) 
{
    set<int> unique_nums;
    
    sort(numbers.begin(), numbers.end());
    
    do 
    {
        for (int i = 1; i <= numbers.length(); i++) 
        {
            string sub = numbers.substr(0, i);
            unique_nums.insert(stoi(sub));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    int answer = 0;
    
    for (set<int>::iterator it = unique_nums.begin(); it != unique_nums.end(); ++it) 
    {
        if (isPrime(*it)) 
        {
            answer++;
        }
    }
    
    return answer;
}