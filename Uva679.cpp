#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int s[1<<maxn];

int main()
{
    int t;
    while(cin>>t)
    {
        if (t == -1)
            break;
        int D,I;
        while(t--)
        {
            int k = 1;
            cin>>D>>I;
            for (int i = 0;i<D-1;i++)
            {
                if (I%2)
                {
                    k = k*2;
                    I = (I+1)/2;
                }
                else
                {
                    k = k*2 + 1;
                    I = I/2;
                }
            }
            cout<<k<<endl;
        }
    }

    return 0;
}
