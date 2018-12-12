#include<bits/stdc++.h>
using namespace std;
const int maxlen = 100+10;
char data[maxlen][maxlen];
int cnt;
int n,m;

void dfs(int x,int y)
{
    int next[8][2] = {
    {-1,0},{-1,1},{0,1},{1,1},
    {1,0},{1,-1},{0,-1},{-1,-1}
    };
    for (int i = 0;i<8;i++)
    {
        int tx = x+next[i][0];
        int ty = y+next[i][1];
        if (tx < 0||tx >= n||ty < 0||ty >= m)
            continue;
        if (data[tx][ty] == '@')
        {
            data[tx][ty] = '*';
            dfs(tx,ty);
        }
    }
}

int main()
{
    while(cin>>n>>m&&n&&m)
    {
        cnt = 0;
        for (int i = 0;i<n;i++)
            for (int j = 0;j<m;j++)
                cin>>data[i][j];
        for (int i = 0;i<n;i++)
            for (int j = 0;j<m;j++)
            {
                if (data[i][j] == '@')
                {
                    cnt++;
                    data[i][j] = '*';
                    dfs(i,j);
                }
            }
        cout<<cnt<<endl;
    }

    return 0;
}
