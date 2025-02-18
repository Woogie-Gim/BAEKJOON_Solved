#include<iostream>
#include<algorithm>

using namespace std;

struct student
{
	string name;
	int kor;
	int eng;
	int math;
};

int n;

bool cmp(struct student st1, struct student st2)
{
	if(st1.kor>st2.kor)
    {
		return true;	
	}
	else if(st1.kor==st2.kor)
    {
		if(st1.eng<st2.eng)
        {
			return true;	
		}
		else if(st1.eng==st2.eng)
        {
			if(st1.math>st2.math) 
            {
				return true;	
			}
			else if(st1.math==st2.math)
            {
				if(st1.name<st2.name) 
                {
					return true;	
				}
				else 
                {
					return false;	
				}
			}
		}
	}
	return false;
}

int main()
{
	cin>>n;
	
	struct student s[n];
	
	for(int i=0;i<n;i++)
    {
		cin>>s[i].name;
		cin>>s[i].kor;
		cin>>s[i].eng;
		cin>>s[i].math;
	}	
	
	sort(s,s+n,cmp);
	
	for(int i=0;i<n;i++)
    {
		cout<<s[i].name<<'\n';
	}
}