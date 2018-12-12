#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int times = 1;
    while(cin>>n&&n)
    {
        printf("Scenario #%d\n",times++);
        map<int,int> team;
        for (int i = 0;i<n;i++)
        {
            int t,a;
            cin>>t;
            while(t--&&cin>>a)
                team[a] = i;
        }

        queue<int> qt,qn[10010];
        while(1)
        {
            int x;
            string op;
            cin>>op;
            if (op[0] == 'S')
                break;
            else if (op[0] == 'D')
            {
                int t = qt.front();
                cout<<qn[t].front()<<endl;
                qn[t].pop();
                if (qn[t].empty())
                    qt.pop();
            }
            else if (op[0] == 'E')
            {
                cin>>x;
                int t = team[x];
                if (qn[t].empty())
                    qt.push(t);
                qn[t].push(x);
            }
        }
        cout<<endl;

    }

    return 0;
}
