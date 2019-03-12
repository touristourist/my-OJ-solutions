#include<bits/stdc++.h>
using namespace std;

struct Time{
	int s,e;
};

Time t[100];

bool cmp(const Time& t1,const Time& t2)
{
	return t1.e<t2.e;
}

int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&(t[i].s),&(t[i].e));
		}
		sort(t,t+n,cmp);
		
		int num=0,nowend=0;
		for(int i=0;i<n;i++)
		{
			if(t[i].s>=nowend)
			{
				nowend=t[i].e;
				num++;
			}
		}
			printf("%d\n",num);
	}
	

}
