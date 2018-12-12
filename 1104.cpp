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
    int a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    int b1,b2,b3,b4,b5,b6;
    b1 = a1;
    b2 = a2;
    b3 = a3;
    b4 = a4;
    b5 = a5;
    b6 = a6;
    int m = a1*1+a2*2+a3*3+a4*5+a5*10+a6*20;
    int sum = 0;
    for (int i = 1;i<=m;i++)
    {
        a1 = b1;
        a2 = b2;
        a3 = b3;
        a4 = b4;
        a5 = b5;
        a6 = b6;
        int w = i;
        while(w>0)
        {
            if (w>=20&&a6>0)
            {
                w -= 20;
                a6--;
            }
            else if (w>=10&&a5>0)
            {
                w -= 10;
                a5--;
            }
            else if (w>=5&&a4>0)
            {
                w -= 5;
                a4--;
            }
            else if (w>=3&&a3>0)
            {
                w -= 3;
                a3--;
            }
            else if (w>=2&&a2>0)
            {
                w -= 2;
                a2--;
            }
            else if (a1>0)
            {
                w -= 1;
                a1--;
            }
            if (a1 == 0&&a2 == 0&&a3 == 0&&a4 == 0&&a5 == 0&&a6 == 0)
                break;
            if (w <= 0)
                break;
        }
        if (w == 0)
            sum++;
    }
    cout<<"Total="<<sum<<endl;

    return 0;
}

