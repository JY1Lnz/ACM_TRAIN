#include<bits/stdc++.h>
using namespace std;

int ji = 0;

void init(int A[2][2],int B[2][2])
{
    for (int i = 0;i<2;i++)
        for (int j = 0;j<2;j++)
            B[i][j] = A[i][j];
}

void matrixmulti(int A[2][2],int B[2][2])
{
    int C[2][2];
    for (int i = 0;i<2;i++)
        for (int j = 0;j<2;j++)
        {
            int sum = 0;
            for (int x = 0;x<2;x++)
            {
                sum += (A[i][x]*B[x][j])%10000;
            }
            C[i][j] = sum%10000;
            //cout<<sum<<endl;
        }
    init(C,B);
}


int main()
{
    //int a[2][2] = {1,1,1,0};
    int n;

    while(cin>>n&&n!=-1)
    {
        int a[2][2] = {1,1,1,0};
        int temp[2][2] = {1,0,0,1};
        while(n)
        {
            if (n%2 != 0)
            {
                //int temp[2][2];
                matrixmulti(a,temp);
            }
            matrixmulti(a,a);
            n/=2;
        }
        cout<<temp[0][1]<<endl;
    }



    return 0;
}
