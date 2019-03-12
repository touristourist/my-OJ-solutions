#include<iostream>
using namespace std;

//int order[100];

#define up 6
#define down 4
#define stop 5

int main()
{
	int N;
	while(cin>>N&&N!=0)
	{
		int nowfl=0,nextfl=0;
		int time=0;
		for(int i=0;i<N;i++)
		{
			cin>>nextfl;
			if(nextfl>nowfl)
				time+=(nextfl-nowfl)*up+stop;
			else
				time+=(nowfl-nextfl)*down+stop;
				
			nowfl=nextfl; 
		}
		cout<<time<<endl;
	}
	
	
}
