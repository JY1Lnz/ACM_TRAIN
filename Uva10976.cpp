#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<pair<int,int> > data;
        for (int y = n+1;y<=2*n;y++)
        {
            int zi = y-n;
            int mu = y*n;
            int yue = __gcd(zi,mu);
            if (zi/yue == 1)
                data.push_back(make_pair(mu/yue,y));
        }
        cout<<data.size()<<endl;
        for (int i = 0;i<data.size();i++)
            printf("1/%d = 1/%d + 1/%d\n",n,data[i].first,data[i].second);
    }

    return 0;
}
