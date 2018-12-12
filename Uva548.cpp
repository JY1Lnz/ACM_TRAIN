#include<bits/stdc++.h>
using namespace std;

const int maxv = 10000+10;
int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;

bool read_line(int * a)
{
    string s;
    getline(cin,s);
    istringstream iss(s);
    n = 0;
    int x;
    while(iss>>x)
        a[n++] = x;
    return n>0;
}

int build(int L1,int R1,int L2,int R2)
{
    if (L1 > R1)
        return 0;//empty tree
    int root = post_order[R2];
    int p = L1;
    while(in_order[p] != root)
        p++;
    int cnt = p-L1;//left tree number
    lch[root] = build(L1,p-1,L2,L2+cnt-1);
    rch[root] = build(p+1,R1,L2+cnt,R2-1);
    return root;
}

int print(int x)
{
    queue<int> q;
    int root = x;
    q.push(x);
    while(!q.empty())
    {
        root = q.front();
        cout<<root<<endl;
        if (lch[root] != 0)
            q.push(lch[root]);
        if (rch[root] != 0)
            q.push(rch[root]);
        q.pop();
    }
}

int best,best_sum;

void dfs(int u,int sum)
{
    sum += u;
    if (!lch[u]&&!rch[u])
    {
        if (sum < best_sum||(sum == best_sum&&u<best))
            best = u,best_sum = sum;
    }
    if (lch[u])
        dfs(lch[u],sum);
    if (rch[u])
        dfs(rch[u],sum);

}

int main()
{
    while(read_line(in_order))
    {
        read_line(post_order);
        build(0,n-1,0,n-1);
        best_sum = 10000000;
        dfs(post_order[n-1],0);
        cout<<best<<endl;
    }

    return 0;
}
