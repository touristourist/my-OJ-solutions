#include<iostream>
#include<stdio.h>
using namespace std;

int bin[1001];  //���鼯set[]���� 

int find(int x)
{
	int r=x;
	while(r!=bin[r])
		r=bin[r];
	//�ҵ���r����·��ѹ�� 
	int i=x;
	while(i!=r)
	{
		int j=bin[i];
		bin[i]=r;
		i=j;
	}
	return r;
}

void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)	
		bin[fx]=fy;    //�򵥴�����x���ڵ������뵽y�ĸ��ڵ��� 
}


int main()
{
	int N,M;
	
	while(scanf("%d",&N)!=EOF&&N!=0)
	{
		scanf("%d",&M);
		//���鼯һ��ʼ��ʼ��ʱ�����ڵ�ʱ�����ģ�����ÿ���ڵ����һ���� 
		for(int i=1;i<=N;i++)
			bin[i]=i;
		
		for(int i=0;i<M;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			merge(u,v); 
		}
		//�����ж��ٸ���ͨ����������ÿ�����ĸ��ڵ㲢�鼯���� 
		int num=0;
		for(int i=1;i<=N;i++)
			if(bin[i]==i)
				num++;
		//ֻ��num-1�� 
		printf("%d\n",num-1);
	}
}
