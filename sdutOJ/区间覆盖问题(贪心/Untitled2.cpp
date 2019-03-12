#include<bits/stdc++.h>
using namespace std;

int lin[50];
int interval[50];

bool cmp(const int& i1,const int &i2)
{
	return i1>i2;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			cin>>lin[i];
		sort(lin,lin+n);
		int total=lin[n-1]-(lin[0]-1);
		int inte=0;
		int j=0;
		for(int i=0;i<n-1;i++)
		{
			if(lin[i]!=lin[i+1])
			{
				interval[j++]=lin[i+1]-1-(lin[i]);
				inte++;	
			}	
		}
		sort(interval,interval+inte,cmp);
		for(int i=1;i<m;i++)
			total-=interval[i-1];
		
		cout<<total<<endl;
	}
	
}
