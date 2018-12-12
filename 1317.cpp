#include<bits/stdc++.h>
using namespace std;
//²é²¢¼¯

int data[110];
void init()
{
    for (int i = 1;i<=109;i++)
        data[i] = i;
}

int get_head(int t)
{
    if (data[t] == t)
        return t;
    else
    {
        data[t] = get_head(data[t]);
        return data[t];
    }
}

void merg(int l,int r)
{
    int head_l,head_r;
    head_l = get_head(l);
    head_r = get_head(r);
    if (head_l!=head_r)
    {
        data[head_r] = head_l;
    }
    return;
}
int main()
{
    //ifstream cin ("test.in");
    int n,m;
    cin>>n>>m;
    init();
    //for (int i = 1;i<=n;i++)
        //cout<<data[i]<<' ';
    //cout<<endl;
    int l,r;
    while(m--)
    {
        cin>>l>>r;
        merg(l,r);
    }
    int sum = 0;
    //for (int i = 1;i<=n;i++)
        //cout<<data[i]<<' ';
    //cout<<endl;
    for (int i = 1;i<=n;i++)
        if (data[i] == i)
            sum++;
    cout<<sum<<endl;

    return 0;
}
