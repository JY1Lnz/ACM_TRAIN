#include<bits/stdc++.h>
using namespace std;

int head[26];
int num;
bool flag = false;
vector<int> data[26];
void Input(string s)
{
    cout<<s<<endl;
    data[s[0]-'a'].push_back(s[s.length()-1]-'a');
    head[s[0]-'a']++;
}

void dfs(int u,int sum)
{
    if (num == sum)
    {
        flag = true;
        return;
    }
    for (int i = 0;i<data[u].size();i++)
    {
        dfs(data[u][i],num+1);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for (int i = 0;i<26;i++)
            data[i].clear();
        flag = false;
        memset(head,0,sizeof(head));
        string s;
        cin>>num;
        for (int i = 0;i<num;i++)
        {
            cin>>s;
            Input(s);
        }
        char first;
        for (int i = 0;i<26;i++)
        {
            if (!head[i])
            {
                dfs(i,1);
                if (flag)
                    break;
            }
        }
        if (flag)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }

    return 0;
}
/*
3
3
acm
malform
mouse
*/
