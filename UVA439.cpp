#include<bits/stdc++.h>
using namespace std;

int data[10][10];
int vis[10][10];
int startx,starty,endx,endy;
struct Node
{
    int x;
    int y;
    int step;
};

int Solve()
{
    int next[8][2] = {{-2,1},{-1,2},{1,2},{2,1},
                    {2,-1},{1,-2},{-1,-2},{-2,-1}};
    queue<Node> q;
    Node first = {startx,starty,0};
    vis[startx][starty] = 1;
    q.push(first);
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        if (x == endx&&y == endy)
            return step;
        for (int i = 0;i<8;i++)
        {
            int tx = x + next[i][0];
            int ty = y + next[i][1];
            if (tx < 1||tx > 8||ty < 1||ty > 8)
                continue;
            if (vis[tx][ty] == 0)
            {
                Node nextnode = {
                    tx,ty,step+1
                };
                vis[tx][ty] = 1;
                q.push(nextnode);
            }
        }
        q.pop();
    }
}

int main()
{
    char start[3],ends[3];
    while(cin>>start>>ends)
    {
        startx = start[1]-'0';
        starty = start[0]-'a'+1;
        endx = ends[1]-'0';
        endy = ends[0]-'a'+1;
        memset(vis,0,sizeof(vis));
        int step = Solve();
        printf("To get from %s to %s takes %d knight moves.\n",start,ends,step);
    }

    return 0;
}
