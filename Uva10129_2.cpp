#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int maxn = 30;
int n;
int g[maxn][maxn],vis[maxn];
int in[maxn],out[maxn];

void init()
{
    memset(g,0,sizeof(g));//��ͼ
    memset(vis,0,sizeof(vis));//��ͨ��
    memset(in,0,sizeof(in));//������
    memset(out,0,sizeof(out));//��ĳ���
}
void input()
{
    int u,v,len;
    string word;
    cin>>n;
    while(n--)
    {
        cin>>word;
        len = word.length();
        u = word[0]-'a'+1;
        v = word[len-1]-'a'+1;
        //�����u->v
        out[u]++;
        in[v]++;
        g[u][v] = g[v][u] = 1;//��ͼ������ͼ��Ӧ������ͼ
    }
    return;
}

void dfs(int i)
{
    int j;
    for (j = 1;j<=26;j++)
        if (g[i][j]&&!vis[j])
        {
            vis[j] = 1;
            dfs(j);
        }
}

int DFS()
{
    int i,cnt;
    for (cnt = 0,i = 1;i<=26;i++)
    {
        if (in[i]||out[i])//�������д˵�
        {
            if (!vis[i])//�˵�δ������
            {
                vis[i] = 1;
                cnt++;
                dfs(i);
            }
        }
    }
    if (cnt > 1)
        return 0;
    else
        return 1;
}

int Euler()
{
    int i;
    int n1,n2;
    n1 = n2 = 0;
    int flag = 1;
    for (i = 1;i<=26;i++)
    {
        if (out[i]-in[i] == 1)
        {
            n1++;
            if (n1>1)
            {
                flag = 0;
                break;
            }
        }
        else if(in[i]-out[i] == 1)
        {
            n2++;
            if (n2>1)
            {
                flag = 0;
                break;
            }
        }
        else if (abs(in[i]-out[i]) > 1)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        return 1;
    else
        return 0;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        init();
        input();

        if (!DFS())
        {
            printf("The door cannot be opened.\n");
        }
        else
        {
            if (!Euler())
            {
                printf("The door cannot be opened.\n");
            }
            else
                printf("Ordering is possible.\n");
        }
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
