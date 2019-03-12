#include<iostream>
using namespace std;

int lcd(int a,int b)
{
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	int c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a*b/lcd(a,b)<<endl;
	}
}
