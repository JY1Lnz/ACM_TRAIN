#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int n = 0,x = b;
    int data[10];
    while(x != 0)
    {
        data[n++] = a*(x%10);
        x/=10;
    }
    printf("%d\n*%d\n",a,b);
    printf("---\n");
    if (b>10)
    {
    for (int i = 0;i<n;i++)
        cout<<data[i]<<endl;
    printf("---\n");
    }
    printf("%4d\n",a*b);

    return 0;
}
