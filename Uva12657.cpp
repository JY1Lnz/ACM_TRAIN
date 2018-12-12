#include<bits/stdc++.h>
using namespace std;
//定义inv来存储是否处于反向状态
//反向状态时1，2操作互相调换
int DATA[100010],RIGHT[100010],LEFT[100010];

void link(int L,int R)//将两个结点链接L为左边点，R为右边点
{
    RIGHT[L] = R;
    LEFT[R] = L;
}


int main()
{
    int n,m;
    int times = 0;
    while(cin>>n>>m)
    {
        bool inv = false;
        for (int i = 1;i<=n;i++)//链表初始化
        {
            LEFT[i] = i-1;
            RIGHT[i] = (i+1)%(n+1);
        }
        RIGHT[0] = 1;
        LEFT[0] = n;

        int op,x,y;

        while(m--)
        {
            cin>>op;
            if (op == 4)
                inv = !inv;
            else
            {
                cin>>x>>y;
                if(op == 3 && RIGHT[y] == x) swap(x, y);
                if (inv&&op != 3)
                    op = 3 - op;
                int XR = RIGHT[x],XL = LEFT[x],YR = RIGHT[y],YL = LEFT[y];
                if (op == 3)
                {
                    if (RIGHT[x] == y)
                    {

                        link(XL,y);
                        link(y,x);
                        link(x,YR);
                    }
                    else
                    {
                        link(XL,y);
                        link(y,XR);
                        link(YL,x);
                        link(x,YR);
                    }
                }
                else if (op == 1&&x != LEFT[y])
                {
                    link(XL,XR);
                    link(YL,x);
                    link(x,y);
                }
                else if (op == 2&&x != RIGHT[y])
                {
                    link(XL,XR);
                    link(x,YR);
                    link(y,x);

                }
            }
        }

        int b = 0;
        long long ans = 0;
        for (int i = 1;i<=n;i++)
        {
            b = RIGHT[b];
            if (i%2 == 1)
                ans += b;
        }
        if (inv && n%2 == 0)
            ans = (long long)n*(n+1)/2 - ans;
        printf("Case %d: %lld\n",++times,ans);
        }


    return 0;
}
