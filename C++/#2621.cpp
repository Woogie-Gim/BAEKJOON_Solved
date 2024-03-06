#include <iostream>

using namespace std;

char color[6];
int number[10] = { 0, };
int ans = 0;

void ruleOne() 
{
	int flagC = 1;
	for (int i = 0; i < 4; i++) 
    {
		if (color[i] != color[i + 1]) 
        {
			flagC = 0;
			break;
		}
	}
    
	int flagN;
    
	for (int i = 1; i <= 5; i++) 
    {
		flagN = 1;
		for (int j = 0; j < 5; j++) 
        {
			flagN *= number[i + j];
		}
		if (flagN == 1) break;
	}
    
	int temp = 0;
    
	if (flagC == 1 && flagN == 1) 
    {
		for (int i = 9; i >= 1; i--) 
        {
			if (number[i] != 0) 
            {
				temp = 900 + i;
				break;
			}
		}
	}
	if (temp > ans) ans = temp;
}

void ruleTwo() 
{
	int num=0;
    
	for (int i = 1; i <= 9; i++) 
    {
		if (number[i] == 4) 
        {
			num = i;
			break;
		}
	}
    
	int temp=0;
    
	if (num != 0) 
    {
		temp = 800 + num;
	}
	if (temp > ans) ans = temp;
}

void ruleThree() 
{
	int threesame = 0;
	int twosame=0;
    
	for (int i = 1; i <= 9; i++) 
    {
		if (number[i] == 3) 
        {
			threesame = i;
		}
		if (number[i] == 2) 
        {
			twosame = i;
		}
	}
    
	int temp=0;
    
	if ((threesame != 0) && (twosame != 0)) 
    {
		temp = threesame * 10 + twosame + 700;
	}
    
	if (temp > ans) ans = temp;
}

void ruleFour() 
{
	int flagC = 1;
    
	for (int i = 0; i < 4; i++) 
    {
		if (color[i] != color[i + 1]) 
        {
			flagC = 0;
			break;
		}
	}
    
	int temp=0;
    
	if (flagC == 1) 
    {
		for (int i = 9; i >= 1; i--) 
        {
			if (number[i] != 0) 
            {
				temp = i + 600;
				break;
			}
		}
	}
    
	if (temp > ans) ans = temp;
}

void ruleFive() 
{
	int flagN;
    
	for (int i = 1; i <= 5; i++) 
    {
		flagN = 1;
        
		for (int j = 0; j < 5; j++) 
        {
			flagN *= number[i + j];
		}
        
		if (flagN == 1) break;
	}
    
	int temp=0;
    
	if (flagN == 1) 
    {
		for (int i = 9; i >= 1; i--) 
        {
			if (number[i] != 0) 
            {
				temp = i + 500;
				break;
			}
		}
	}
    
	if (temp > ans) ans = temp;
}

void ruleSix() 
{
	int threesame=0;
    
	for (int i = 1; i <= 9; i++) 
    {
		if (number[i] == 3) 
        {
			threesame = i;
			break;
		}
	}
    
	int temp=0;
    
	if (threesame != 0) 
    {
		temp = threesame + 400;
	}
	
	if (temp > ans) ans = temp;
}

void ruleSeven() 
{
	int twosame1 = 0;
	int twosame2 = 0;
    
	for (int i = 1; i <= 9; i++) 
    {
		if (number[i] == 2) 
        {
			twosame1 = i;
			break;
		}
	}
    
	for (int i = twosame1 + 1; i <= 9; i++) 
    {
		if (number[i] == 2) 
        {
			twosame2 = i;
			break;
		}
	}
    
	int temp=0;
    
	if ((twosame1 != 0) && (twosame2 != 0)) 
    {
		temp = twosame2 * 10 + twosame1 + 300;
	}
    
	if (temp > ans) ans = temp;
}

void ruleEight() 
{
	int twosame = 0;
    
	for (int i = 1; i <= 9; i++) 
    {
		if (number[i] == 2) 
        {
			twosame = i;
			break;
		}
	}
    
	int temp=0;
    
	if (twosame != 0) 
    {
		temp = twosame + 200;
	}
    
	if (temp > ans) ans = temp;
}

void ruleNine() 
{
	if (ans == 0) 
    {
		for (int i = 9; i >= 1; i--) 
        {
			if (number[i] != 0) 
            {
				ans = i + 100;
				break;
			}
		}
	}
}

int main() 
{
	for (int i = 0; i < 5; i++) 
    {
		cin >> color[i];
		int temp;
		cin >> temp;
		number[temp]++;
	}
	ans = 0;
	ruleOne();
	ruleTwo();
	ruleThree();
	ruleFour();
	ruleFive();
	ruleSix();
	ruleSeven();
	ruleEight();
	ruleNine();
	cout << ans << '\n';
	return 0;
}