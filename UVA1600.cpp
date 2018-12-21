#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int n,m,k;
int map[22][22][22];
int vis[22][22];

struct Node
{
    int x;
    int y;
    int step;
    int knum;
    Node():x(0),y(0),step(0),knum(0){}
};

int Solve()
{
    int next[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    Node first(1,1,0,0);
    queue<Node> q;
    q.push(first);
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        int knum = q.front().knum;
        if (x == m&&y == n)
            return step;
        for (int i = 0;i<4;i++)
        {
            int tx = x + next[i][0];
            int ty = y + next[i][1];
            if (tx < 1||tx > m||ty < 1||ty > n)
                continue;
            int kx = knum;
            if (data[tx][ty] == 1)
                kx++;
            else
                kx = 0;
            if (kx > k)
                continue;
            if (vis[tx][ty][kx] == 1)
                continue;
            q.push(Node(ts,ty,step+1,kx));
            vis[tx][ty][kx = 1;]
        }

        q.pop();
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        cin>>k;
        for (int i = 1;i<=m;i++)
            for (int j = 1;j<=n;j++)
                cin>>map[i][j];
        memset(vis,0,sizeof(vis));
        int step = Solve();
        cout<<step<<endl;
    }

    return 0;
}
