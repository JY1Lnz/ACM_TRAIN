#include<bits/stdc++.h>
using namespace std;



struct Matrix
{
    int data[2][2];
};

Matrix one = {1,0,0,1};

Matrix chenfa(Matrix a,Matrix b)
{
    Matrix ans;
    for (int i = 0;i<2;i++)
        for (int j = 0;j<2;j++)
        {
            ans.data[i][j] = 0;
            for (int k = 0;k<2;k++)
                ans.data[i][j] += (a.data[i][k]%10000*b.data[k][j]%10000)%10000;
        }
    return ans;
}

Matrix quick(Matrix a,int n)
{

    if (n == 0)
        return one;
    if (n%2 == 0)
        return quick(chenfa(a,a),n/2);
    return chenfa(a,quick(chenfa(a,a),n/2));
}

int main()
{
    int n;
    while(cin>>n)
    {
        Matrix a = {1,1,1,0};
        Matrix test = quick(a,n);
        cout<<test.data[0][1]%10000<<endl;
    }



    return 0;
}
