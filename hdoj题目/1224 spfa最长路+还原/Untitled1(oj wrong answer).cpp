#include<bits/stdc++.h>
using namespace std;

//spfa求最长路 

#define LIT -100000

class Edge{
	public:
		int from,to,cost;
	Edge(int f,int t,int c):from(f),to(t),cost(c) {}
};

typedef pair<int,int> Pint;

int city[105];  //city's intererst 
bool inqueue[105];  //是否在队列中 
int dlong[105];  //记录每个点的临时最长路径 
int visitcount[105];  //访问次数 


int father[105];
stack<int> st;

int main()
{
	freopen("a.txt","r",stdin);
	
	int T,N,M;
	cin>>T;
	int cas=1;
	while(T--)
	{	
		vector<vector<Edge> > graph(105);   //图的数据结构 
		memset(father,0,sizeof(father));
//		memset(visitcount,0,sizeof(visitcount));
		
		cin>>N;
		for(int i=1;i<=N;i++)
			cin>>city[i];
		queue<pair<int,int> > Q;  //(dlong[i],i)
		for(int i=1;i<=N;i++)
		{
			inqueue[i]=(i==1);
			dlong[i]=(i==1)?0:LIT;
			visitcount[i]=(i==1)?1:0;
		}
		
		cin>>M;
		int ffrom,tto;
		for(int i=0;i<M;i++)
		{
			cin>>ffrom>>tto;
			if(tto!=N+1)
				graph[ffrom].push_back(Edge(ffrom,tto,city[tto]));
		}
		
		Q.push(make_pair(dlong[1],1));
		while(!Q.empty())
		{
			Pint tem=Q.front();
			Q.pop();
			inqueue[tem.second]=false;
			visitcount[tem.second]++;
//			if(visitcount[tem.second]>N)
//							;//				cout<<"负权环";
			
			for(int k=0;k<graph[tem.second].size();k++)
			{
				int u=tem.second,v=graph[tem.second][k].to;
				int lencost=graph[tem.second][k].cost;
				if(dlong[u]+lencost>dlong[v]&&dlong[u]>=0)
				{
					dlong[v]=dlong[u]+lencost;
					father[v]=u;
					
//					Q.push(make_pair(dlong[v],v));
					if(inqueue[v]==false)
					{
						inqueue[v]=true;
						Q.push(make_pair(dlong[v],v));
					}
						
					
				}
					
			}
		}
		
		int longest=LIT,li=0;
		for(int i=1;i<=N;i++)
		{
			if(dlong[i]>longest)
			{
				longest=dlong[i];
				li=i;
			}
		}
		
		cout<<"CASE "<<cas++<<"#"<<endl;
		cout<<"points : "<<longest<<endl;
		cout<<"circuit : ";
		
		int sea=li;
		while(sea!=1)
		{
			st.push(sea);
			sea=father[sea];
		}
		cout<<1;
		while(!st.empty())
		{
			cout<<"->"<<st.top();
			st.pop();
		}
		cout<<"->"<<1<<endl<<endl;
	}
} 
