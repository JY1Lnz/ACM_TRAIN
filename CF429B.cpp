#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000+10;
long long dp[5][maxn][maxn];
long long data[maxn][maxn];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=m;j++)
            cin>>data[i][j];

    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=m;j++)
            dp[1][i][j] = data[i][j]+max(dp[1][i-1][j],dp[1][i][j-1]);
        for (int j = m;j>=1;j--)
            dp[2][i][j] = data[i][j]+max(dp[2][i-1][j],dp[2][i][j+1]);
    }

    for (int i = n;i>=1;i--)
    {
        for (int j = 1;j<=m;j++)
            dp[4][i][j] = data[i][j]+max(dp[4][i][j-1],dp[4][i+1][j]);
        for (int j = m;j>=1;j--)
            dp[3][i][j] = data[i][j]+max(dp[3][i][j+1],dp[3][i+1][j]);
    }

    long long ans = 0;
    for (int i = 2;i<n;i++)
        for (int j = 2;j<m;j++)
        {
            long long x1 = dp[1][i][j-1]+dp[3][i][j+1]+dp[4][i+1][j]+dp[2][i-1][j];
            long long x2 = dp[1][i-1][j]+dp[3][i+1][j]+dp[4][i][j-1]+dp[2][i][j+1];
            ans = max(ans,max(x1,x2));
        }
    cout<<ans<<endl;


    return 0;
}
