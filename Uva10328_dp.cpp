#include<bits/stdc++.h>
using namespace std;
//大数
//递推没问题
const int maxn = 100+10;
long long dp[maxn][2];
int n,k,u;

long long dp_slove()
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1;i<=n;i++)
    {
        int sum = dp[i-1][0]+dp[i-1][1];
        dp[i][0] = sum;
        if (i <= u)
            dp[i][1] = sum;
        else if (i == u+1)
            dp[i][1] = sum-1;
        else
            dp[i][1] = sum-dp[i-u-1][0];
    }

    return dp[n][0]+dp[n][1];

}

int main()
{
    while(cin>>n>>k)
    {
        u = k-1;
        memset(dp,0,sizeof(dp));

        cout<<(1<<n)-dp_slove()<<endl;
        cout<<(1<<100)<<endl;
    }
}
