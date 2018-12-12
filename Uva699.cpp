#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int sum[maxn];

void build(int pos)
{
    int v;
    cin>>v;
    if (v == -1)
        return;
    sum[pos] += v;
    build(pos-1);
    build(pos+1);
}

bool init()
{
    int v;
    cin>>v;
    if (v == -1)
        return false;
    memset(sum,0,sizeof(sum));
    int pos = maxn/2;
    sum[pos] += v;
    build(pos-1);
    build(pos+1);
    return true;
}

int main()
{
    int cnt = 0;
    while(init())
    {
        printf("Case %d:\n",++cnt);
        int i = 0;
        while(sum[i] == 0) i++;
        cout<<sum[i++];
        while(sum[i] != 0)
            cout<<' '<<sum[i++];
        cout<<endl<<endl;
    }

    return 0;
}
