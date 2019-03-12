#include<bits/stdc++.h>
using namespace std;

class edge{
	public:
		int from,to,cost;
		edge(int f,int t,int c):from(f),to(t),cost(c) {}
};

vector<vector<edge> > graph(105);

bool inqueue[105];
int visitcount[105];
int d[105];
int city[105];

int father[105];

//typedef pair<int,int> Pint;

int main()
{
	int t,n,m;
	scanf("%d",&t);
	int cou=1;
	int T=t;
	while(T--)
	{
		memset(d,-1,sizeof(d));
		memset(father,0,sizeof(father));
		memset(inqueue,0,sizeof(inqueue));
		memset(visitcount,0,sizeof(visitcount));
		memset(city,0,sizeof(city));
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",city+i);
			graph[i].clear();   //graph按行清空 
		}
			
		city[n+1]=city[1];   //最高级的和最低级的相等 
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int from,to;
			scanf("%d %d",&from,&to);
			graph[from].push_back(edge(from,to,city[to]));
		}
		
		queue<int> Q;
		d[1]=0;
		Q.push(1);
		while(!Q.empty())
		{
			int u=Q.front();
			Q.pop();
			inqueue[u]=false;
			visitcount[u]++;
			if(visitcount[u]>n)
				;//负权圈
				
			for(int k=0;k<graph[u].size();k++)
			{
				int cost=graph[u][k].cost;
				int v=graph[u][k].to;
				if(d[v]<d[u]+cost)
				{
					d[v]=d[u]+cost;
					father[v]=u;
					if(!inqueue[v])
					{
						Q.push(v);
						inqueue[v]=true;
					}
				}
			} 
		} 
		
		
		
		//最终要得到到序号最大的顶点的最长路径
		int points=d[n+1];
		stack<int> s;
		int node=father[n+1];
		while(node!=1)
		{
			s.push(node);
			node=father[node];
		}
		printf("CASE %d#\n",cou++);
		printf("points : %d\n",points);
		printf("circuit : 1");
		while(!s.empty())
		{
			printf("->%d",s.top());
			s.pop();
		}
		printf("->1\n");   //最后一行只输出一个\n，其他行输出两个\n 
		if(cou!=t+1)
			printf("\n");
	}
}
