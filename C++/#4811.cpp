#include <iostream>
#include <algorithm>

using namespace std; 

long long dp[31][31]; 

long long dfs(int w, int h)
{
	if (h == -1)return 0; 
    
	if (w == 0)return 1; 
    
	long long& ret = dp[w][h]; 
    
	if (ret)return dp[w][h]; 
    
	ret = dfs(w - 1, h + 1)+ dfs(w, h-1);  
    
	return ret; 
}
int main()
{	
	while (1) 
    {
		int w; cin >> w; 
        
		if (w == 0)return 0; 
        
		cout << dfs(w, 0) << "\n"; 
	}
    
	return 0; 
}