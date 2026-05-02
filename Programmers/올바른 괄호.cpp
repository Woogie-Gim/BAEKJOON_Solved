#include <stdbool.h>
#include <string.h>

bool solution(const char* s) 
{
    int count = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) 
    {
        if (s[i] == '(') 
        {
            count++;
        } 
        else if (s[i] == ')') 
        {
            count--;
            
            if (count < 0) 
            {
                return false;
            }
        }
    }
    
    if (count == 0) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}