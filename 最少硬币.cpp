#include<bits/stdc++.h>
using namespace std;

int coin[] = {1,3,5};
int dp[100];
void dp_fun(int num)
{
    dp[0] = 0;
    for (int i = 1;i<=num;i++)
    {
        dp[i] = 9999;
        for (int j = 0;coin[j]<=i&&j<3;j++)
        {
            if (dp[i-coin[j]]+1 < dp[i])
                dp[i] = dp[i-coin[j]]+1;
        }
    }
}

int main()
{
    dp_fun(18);
    for (int i = 0;i<19;i++)
    {
        cout<<i<<"  "<<dp[i]<<endl;
    }

    return 0;
}
