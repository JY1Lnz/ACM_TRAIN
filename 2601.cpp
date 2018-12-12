#include<bits/stdc++.h>
using namespace std;

void init (int team[],int n)
{
    for (int i = 1;i<=n;i++)
        team[i] = i;
}

struct vote
{
    int u;
    int v;
    int w;
};

bool cmp(vote l,vote r)
{
    if (l.w < r.w)
        return true;
    return false;
}

int gethead(int team[],int w)
{
    if (team[w] == w)
        return team[w];
    else
    {
        team[w] = gethead(team,team[w]);
        return team[w];
    }
}

bool merger(int team[],int l,int r)
{
    int head_l = gethead(team,l);
    int head_r = gethead(team,r);
    //cout<<head_l<<' '<<head_r<<endl;
    if (head_l == head_r)
        return false;
    else
        team[head_r] = head_l;
    //cout<<team[head_l]<<' '<<team[head_r]<<endl;
    return true;
}

int main()
{
    //ifstream cin ("test.in");
    int n,m;
    cin>>n>>m;
    int team[n+1];
    vote road[m];
    init(team,n);
    //cout<<2<<endl;
    for (int i = 0;i<m;i++)
        cin>>road[i].u>>road[i].v>>road[i].w;
    sort(road,road+m,cmp);
    int sum = 0;
    int road_num = 0;
    //for (int i = 0;i<m;i++)
        //printf("%d %d %d\n",road[i].u,road[i].v,road[i].w);
    for (int i = 0;i<m;i++)
    {
        //cout<<i<<endl;
        if (merger(team,road[i].u,road[i].v))
        {
            road_num++;
            sum += road[i].w;
        }
        if (road_num == n-1)
            break;
        //cout<<sum<<endl;
        //for (int i = 1;i<=n;i++)
            //printf("%d ",team[i]);
        //cout<<endl;
    }
    cout<<sum<<endl;


    return 0;
}
