#include<iostream>
#include<memory.h>
#include<cstdio>
using namespace std;

const int maxn = 1000000+10;
const int mod = 1000000007;
long long dp[maxn][5];
long long n,m,k,u,v;
long long Cal()
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1;i<=n;i++)
    {
        long long sum = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
        dp[i][2] = sum;
        if (i<=u)
            dp[i][0] = sum;
        else if (i == u+1)
            dp[i][0] = (sum-1)%mod;
        else
            dp[i][0] = (sum-dp[i-u-1][1]-dp[i-u-1][2])%mod;

        if (i<=v)
            dp[i][1] = sum;
        else if (i == v+1)
            dp[i][1] = (sum-1)%mod;
        else
            dp[i][1] = (sum-dp[i-v-1][0]-dp[i-v-1][2])%mod;
    }

    return (dp[n][0]+dp[n][1]+dp[n][2])%mod;
}

int main()
{
    while(cin>>n>>m>>k)
    {
        u = n,v = k;
        long long ans = Cal();
        u = m-1,v = k;
        ans = ((ans-Cal())%mod+mod)%mod;
        cout<<ans<<endl;
    }

    return 0;
}
