#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

const int maxn = 200000+10;
const int maxv = 10000000+10;
int dp[maxn];
int data[maxn];
int vis[maxv];
long long sum;
int n;

long long dp_slove(int i)
{
    memset(vis,0,sizeof(vis));
    for (int j = 0;j<=data[i]+1;j++)
        if (j != data[i])
        {
            dp[i] = j;
            break;
        }
    vis[data[i]] = 1;
    long long sum = dp[i];
    long long big = dp[i];
    for (int j = i+1;j<=n;j++)
    {
        if (data[j] != dp[j-1])
            dp[j] = dp[j-1];
        else
        {
            for (int i = data[j]+1;i <= maxv;i++)
                if (vis[i] == 0)
                {
                    dp[j] = i;
                    break;
                }
        }
        sum += dp[j];
        vis[data[j]] = 1;
    }
    return sum;
}

int main()
{
    while(cin>>n)
    {
        sum = 0;
        for (int i = 1;i<=n;i++)
            cin>>data[i];
        for (int i = 1;i<=n;i++)
        {
            sum += dp_slove(i);
        }
        cout<<sum<<endl;
    }

    return 0;
}
