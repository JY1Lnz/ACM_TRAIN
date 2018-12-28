#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000,INF = 999999;
int first[maxn],next1[maxn];
int u[maxn],v[maxn],w[maxn];
int dis[maxn],vis[maxn];
int n,m,l,r,len;

void init()
{
    for (int i = 1;i<=n;i++)
        dis[i] = INF;
    dis[1] = 0;
    memset(vis,0,sizeof(vis));
    for (int i = 1;i<=n;i++)
        first[i] = -1;
    for (int i = 1;i<=m;i++)
        next1[i] = -1;

}

void input()
{
    for (int i = 1;i<=m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        next1[i] = first[u[i]];
        first[u[i]] = i;
    }
}

void solve()
{
    queue<int> Q;
    Q.push(1);//从1号路开始疏松
    vis[1] = 1;
    while(!Q.empty())
    {
        int k = first[Q.front()];
        while(k != -1)
        {
            if (dis[v[k]] > dis[u[k]]+w[k])
            {
                dis[v[k]] = dis[u[k]]+w[k];
                if (vis[v[k]] == 0)
                {
                    Q.push(v[k]);//被疏松的点进队
                    vis[v[k]] = 1;//记录进队
                }
            }
            k = next1[k];//获取以队首为顶点的路径
        }
        vis[Q.front()] = 0;//记录出队
        Q.pop();
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    init();
    input();
    solve();
    for (int i = 1;i<=n;i++)
        printf("%d ",dis[i]);

    return 0;
}
/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
