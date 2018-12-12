#include<bits/stdc++.h>
using namespace std;

struct A
{
    int x;
    int y;
    bool operator < (const A & t)
    const{
        return (this->x < t.x);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<A> data;
        int sum = 0,x,y;
        for (int i = 0;i<n;i++)
        {
            cin>>x>>y;
            A tmp = {x,y};
            data.insert(tmp);
            sum += x;
        }
        int m = sum/data.size();
        int flag = 1;
        cout<<endl<<endl;
        for (auto po:data)
            cout<<po.x<<' '<<po.y<<endl;
        for (auto po:data)
        {
            if (po.x == m)
                continue;
            int xx = m*2-po.x;
            int yy = po.y;
            A tmp = {xx,yy};
            cout<<data.count(tmp)<<endl;
            if (!data.count(tmp))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }

    return 0;
}
