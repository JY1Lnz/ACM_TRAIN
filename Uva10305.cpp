#include<bits/stdc++.h>
using namespace std;

const int maxn = 100+10;

int data[maxn][maxn];
int c[maxn];
int topo[maxn];
int n,m,t;

bool dfs(int u)
{
    c[u] = -1;//正在访问的结点
    for (int v = 1;v<=n;v++)
        if (data[u][v])
        {
            if (c[v] == -1)
                return false;
            else if (!c[v] && !dfs(v))
                return false;
        }
    c[u] = 1;
    topo[--t] = u;
    return true;
}

bool toposort()
{
    t = n;
    for (int u = 1;u<=n;u++)
        if (!c[u])
            if (!dfs(u))
                return false;
    return true;
}

int main()
{
    while(cin>>n>>m)
    {
        if (n == 0&&m == 0)
            break;
        memset(data,0,sizeof(data));
        memset(c,0,sizeof(c));
        int x,y;
        while(m--)
        {
            cin>>x>>y;
            data[x][y] = 1;
        }

        if (toposort())
            for (int i = 0;i<n;i++)
                cout<<topo[i]<<' ';
        cout<<endl;
    }
}
