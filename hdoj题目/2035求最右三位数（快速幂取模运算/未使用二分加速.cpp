#include<iostream> 
using namespace std;

//δʹ�ö��ּ��� 

int main()
{
	int a,b;
	while(cin>>a>>b&&(a!=0&&b!=0))
	{
		int result=a%1000;
		for(int i=0;i<b-1;i++)
		{
			result=(result*(a%1000))%1000;
		}
		cout<<result<<endl;
	}
	
}
