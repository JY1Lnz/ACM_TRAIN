#include<bits/stdc++.h>
using namespace std;

int head[26];
int num;
bool flag = false;
queue<int> data[26];
void Input(string s)
{
    data[s[0]-'a'].push(s[s.length()-1]-'a');
    head[s[0]-'a'] = 1;
}

void dfs(int u,int sum)
{
    if (sum == num)
    {
        flag = true;
        return;
    }
    for (int i = 0;i<data[u].size();i++)
    {
        if (data[u].size() == 0)
            break;
        int next = data[u].front();
        data[u].pop();
        dfs(next,sum+1);
        data[u].push(next);
    }
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        for (int i = 0;i<26;i++)
            while(!data[i].empty())
                data[i].pop();
        flag = false;
        memset(head,0,sizeof(head));
        string s;
        cin>>num;
        for (int i = 0;i<num;i++)
        {
            cin>>s;
            Input(s);
        }
        for (int i = 0;i<26;i++)
        {
            if (head[i])
            {
                dfs(i,0);
                if(flag)
                    break;
            }
        }
        if (flag)
            cout<<"Ordering is possible."<<endl;
        else
            cout<<"The door cannot be opened."<<endl;
    }
}
/*
3
3
acm
malform
mouse
*/
