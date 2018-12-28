#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 1000+10;
const int INF = 99999;
int map[maxn][maxn];
int vis[maxn];
int div_s[maxn],div_e[maxn];
int n,m,s,e;
int l,r,len;

void dj(int s,int div[])
{
    for (int i = 0; i<n; i++)
    {
        int big = INF;
        int w;
        for (int i = 0; i<n; i++)
        {
            if (vis[i]==0&&div[i] < big)
            {
                big = div[i];
                w = i;
            }
        }
        vis[w] = 1;
        for (int j = 0; j<n; j++)
        {
            if (div[j] > div[w] + map[w][j])
                div[j] = div[w] + map[w][j];
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                if (i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = INF;

        for (int i = 1; i<=m; i++)
        {
            scanf("%d%d%d",&l,&r,&len);
            map[l][r] = len;
            map[r][l] = len;
        }
        scanf("%d%d",&s,&e);
        for (int i = 0; i<n; i++)
        {
            div_s[i] = map[s][i];
            div_e[i] = map[e][i];
        }
        memset(vis,0,sizeof(vis));
        vis[s] = 1;
        dj(s,div_s);
        memset(vis,0,sizeof(vis));
        vis[e] = 1;
        dj(e,div_e);

        int cost = 0;
        for (int i = 0; i<n; i++)
        {
            if (i == s||i == e)
                continue;
            cost = max(cost,div_s[i]+div_e[i]);
        }
        printf("%d\n",cost);
    }


    return 0;
}
