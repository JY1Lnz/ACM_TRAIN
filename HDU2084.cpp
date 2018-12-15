#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;


//2 4 7 11
//1 2 3 4
//
int data[110][110];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(data,0,sizeof(data));
        int n;
        cin>>n;
        for (int i = 1;i<=n;i++)
            for (int j = 1;j<=i;j++)
                cin>>data[i][j];

        for (int i = 1;i<=n;i++)
            for (int j = 1;j<=i;j++)
            {
                data[i][j] = data[i][j] + max(data[i-1][j],data[i-1][j-1]);
            }
        int maxsum = 0;
        for (int i = 1;i<=n;i++)
            maxsum = max(maxsum,data[n][i]);
        cout<<maxsum<<endl;

    }

    return 0;
}
