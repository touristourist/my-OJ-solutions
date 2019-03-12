#include<iostream>
#include<stdio.h>
using namespace std;

int bin[1001];  //并查集set[]数组 

int find(int x)
{
	int r=x;
	while(r!=bin[r])
		r=bin[r];
	//找到根r后再路径压缩 
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
		bin[fx]=fy;    //简单处理，将x所在的树插入到y的根节点下 
}


int main()
{
	int N,M;
	
	while(scanf("%d",&N)!=EOF&&N!=0)
	{
		scanf("%d",&M);
		//并查集一开始初始化时，各节点时独立的，所以每个节点就是一棵树 
		for(int i=1;i<=N;i++)
			bin[i]=i;
		
		for(int i=0;i<M;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			merge(u,v); 
		}
		//计算有多少个连通分量，考虑每棵树的根节点并查集性质 
		int num=0;
		for(int i=1;i<=N;i++)
			if(bin[i]==i)
				num++;
		//只需num-1边 
		printf("%d\n",num-1);
	}
}
