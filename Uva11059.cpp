#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,cnt = 0;
    while(cin>>n)
    {

        int data[n];
        for (int i = 0;i<n;i++)
            cin>>data[i];
        printf("Case #%d: The maximum product is ",++cnt);
        long long sum = -20;
        for (int i = 0;i<n;i++)
        {

            for (int j = i;j<n;j++)
            {
                long long tmp = 1;
                for (int x = i;x<=j;x++)
                    tmp *= data[x];
                sum = max(sum,tmp);
            }
        }
        if (sum < 0)
            cout<<0;
        else
            cout<<sum;
        cout<<'.'<<endl;
        cout<<endl;
    }

    return 0;
}
