#include<bits/stdc++.h>
using namespace std;

int ji = 0;

void init(int A[2][2],int B[2][2])
{
    for (int i = 0;i<2;i++)
        for (int j = 0;j<2;j++)
            B[i][j] = A[i][j];
}

void matrixmulti(int A[2][2],int B[2][2],int C[2][2])
{
    for (int i = 0;i<2;i++)
        for (int j = 0;j<2;j++)
        {
            int sum = 0;
            for (int x = 0;x<2;x++)
            {
                sum += A[i][x]*B[x][j];
            }
            C[i][j] = sum;
            //cout<<sum<<endl;
        }
}

void quickmatrixmulti(int A[2][2],int n,int D[2][2],int X[2][2])
{

    int C[2][2];
    if (n > 1)
    {

        matrixmulti(A,A,C);
        if (n%2 != 0)
            ji++;
        quickmatrixmulti(C,n/2,D,X);
        //cout<<'o'<<endl;
    }
    if (n <=1)
    {
        if (ji == 0)
            init(A,X);
        for (int i = 0;i<ji;i++)
        {
            int T[2][2];
            matrixmulti(D,A,T);
            init(T,X);
        }
    }
}

int main()
{
    int a[2][2] = {1,1,1,0};
    int x[2][2];
    int n;
    while(cin>>n)
    {
        ji = 0;
        quickmatrixmulti(a,n,a,x);
        for (int i = 0;i<2;i++)
        {
            for (int j = 0;j<2;j++)
                cout<<x[i][j]<<' ';
            cout<<endl;
        }
    }

    return 0;
}
