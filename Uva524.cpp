#include<bits/stdc++.h>
using namespace std;

int data[20];
int book[20];
int maxn;
bool primer(int n)
{
    for (int i = 2;i*i <= n;i++)
        if (n%i == 0)
            return false;
    return true;
}

void dfs(int cur)
{
    if (cur == maxn)
    {
        if (primer(data[0]+data[maxn-1]))
        {
            cout<<data[0];
            for (int i = 1;i<maxn;i++)
                cout<<' '<<data[i];
            cout<<endl;
        }
        return;
    }
    for (int i = 2;i<=maxn;i++)
    {
        if (book[i] == 0&&primer(data[cur-1]+i))
        {
            data[cur] = i;
            book[i] = 1;
            dfs(cur+1);
            book[i] = 0;
        }
    }
    return;
}

int main()
{
    int cnt = 0;
    while(cin>>maxn)
    {
        memset(book,0,sizeof(book));
        memset(data,0,sizeof(data));
        data[0] = 1;
        if (cnt != 0)
            cout<<endl;
        printf("Case %d:\n",++cnt);
        dfs(1);
        //cout<<endl;
    }

    return 0;
}
