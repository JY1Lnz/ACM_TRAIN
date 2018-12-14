#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
int data[maxn][maxn];
int vis[maxn][maxn];
//如果一个无向图是连同的且奇数
stack<pair<int,int> > path;
void euler(int u)
{
    for (int v = 0;v < maxn;v++)
        if (vis[u][v] && !data[u][v])
        {
            data[u][v] = data[v][u] = 1;
            euler(v);
            path.push(make_pair(u,v));
        }
}

int main()
{
    int m;
    while(cin>>m)
    {
        int x,y;
        for (int i = 0;i<m;i++)
        {
            cin>>x>>y;
            vis[x][y] = vis[y][x] = 1;
        }

        euler(1);
        while(!path.empty())
        {
            cout<<path.top().first<<' '<<path.top().second<<endl;
            path.pop();
        }
    }

    return 0;
}
