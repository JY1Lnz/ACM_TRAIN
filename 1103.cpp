#include<bits/stdc++.h>
using namespace std;

int jie(int n)
{
    if (n == 1)
        return 2;
    return 2*jie(n-1);
}

int main()
{
    //ifstream cin ("cin.in");
    int n,m;
    cin>>n;
    m = jie(n);
    //cout<<m<<endl;
    int data[m+1][m+1] = {0};
    for (int i = 1;i<=m;i++)
        data[i][i] = 1;
    for (int t = 1;t<=m-1;t++)
    {
        int book[m+1] = {0};
        printf("<%d>",t);
        for (int i = 1;i<=m;i++)
            for (int j = 1;j<=m;j++)
            {
                //cout<<i<<' '<<j<<' '<<data[i][j]<<' '<<book[i]<<' '<<book[j]<<endl;
                if (data[i][j] == 0&&book[i] == 0&&book[j] == 0)
                {
                    data[i][j] = 1;
                    book[i] = 1;
                    book[j] = 1;
                    printf("%d-%d ",i,j);
                }
            }
        cout<<endl;
    }

    return 0;
}

