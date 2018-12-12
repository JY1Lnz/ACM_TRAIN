#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x)
{
    if (IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main()
{
    stack<int> s;
    int n;
    cin>>n;
    while(n--)
    {
        string op;
        cin>>op;
        if (op[0] == 'P')
            s.push(ID(Set()));
        else if (op[0] == 'D')
            s.push(s.top());
        else
        {
            Set x1 = Setcache[s.top()];
            s.pop();
            Set x2 = Setcache[s.top()];
            s.pop();
            Set x;

        }
    }

    return 0;
}
