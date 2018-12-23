#include<iostream>
#include<algorithm>
#include<stack>
#define LL long long
using namespace std;
const int maxn = 100000+10;

LL data[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for (int i = 0;i<n;i++)
            scanf("%lld",&data[i]);

        stack<pair<LL,int> > martix;

        LL maxs = 0;
        LL width;
        for (int i = 0;i<n;i++)
        {
            width = 0;
            while(!martix.empty()&&data[i] < martix.top().first)
            {
                maxs = max(maxs,martix.top().first*(martix.top().second+width));
                width += martix.top().second;
                martix.pop();
            }
            //cout<<maxs<<endl;
                martix.push(make_pair(data[i],1+width));
        }
        while(!martix.empty())
        {
            maxs = max(maxs,martix.top().first*martix.top().second);
            width = martix.top().second;
            martix.pop();
            if (martix.empty())
                break;
            martix.top().second += width;
        }

        printf("%lld\n",maxs);
    }

    return 0;
}

/*
10 2 1 4 5 1 0 3 2 4 1
*/
