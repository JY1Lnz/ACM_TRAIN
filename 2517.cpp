#include<bits/stdc++.h>
using namespace std;

int data[11] = {1};



int main()
{
    for (int i = 1;i<=10;i++)
        data[i] = data[i-1]*i;
    //for (int i = 0;i<=10;i++)
        //cout<<data[i]<<' ';
    int m,n,k;
    cin>>m>>n>>k;
    long long sum = 0;
    sum+=data[k];
    int all = 0;
    cout<<sum<<endl;
    for (int i = 1;i<=k;i++)
    {
        for (int j = n;j>=n-i+1;j--)
            sum*=j;
        sum*=data[n-i];
        all +=sum;
    }
    if (n>k)
        sum *= n-k+1;1
    cout<<all<<endl;

    return 0;
}
