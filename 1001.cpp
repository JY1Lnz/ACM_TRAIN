#include<iostream>
using namespace std;

int data[26][26];

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    for (int i = 1;i<=n;i++)
        printf("(%d,%d)",x,i);
    cout<<endl;
    for (int i = 1;i<=n;i++)
        printf("(%d,%d)",i,y);
    cout<<endl;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
            if (i-j == x-y)
                printf("(%d,%d)",i,j);
    cout<<endl;
    for (int i = n;i>=1;i--)
        for (int j = n;j>=1;j--)
            if (i+j == x+y)
                printf("(%d,%d)",i,j);
    cout<<endl;

    return 0;
}
