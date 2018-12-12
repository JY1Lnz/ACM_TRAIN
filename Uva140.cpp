#include<bits/stdc++.h>
using namespace std;

const int maxn = 10;
int k,len,sum;
string s;
int chart[maxn][maxn];
int que[maxn],book[maxn];
map<char,int> data;
map<int,char> letter;

void init();
void handle_letter();
void handle_string();
void dfs(int cur,int now);

int main()
{
    init();
    //test codes
    for (auto it = data.begin();it != data.end();it++)
        cout<<it->first<<' '<<it->second<<endl;
    for (int i = 0;i<k;i++)
    {
        for (int j = 0;j<k;j++)
        {
            if (chart[i][j] == 1)
                cout<<letter[i]<<"--"<<letter[j]<<endl;
        }
    }

    for (int i = 0;i<len;i++)
        cout<<letter[que[i]]<<' ';
    cout<<endl;

    return 0;
}

void init()
{
    data.clear();
    memset(chart,0,sizeof(chart));
    memset(book,0,sizeof(book));
    cin>>s;
    k = 0;
    len = 0;
    sum = 0;
    handle_letter();
    handle_string();
}

void dfs(int cur,int now)
{
    if (cur == len)
    {
        if (now < k)
            k = now;
        return;
    }
    for (int i = 0;i<len;i++)
    {
        if (book[i] == 0)
        {
            int m = 0;
            for (int j = 0;j<cur;j++)
            {
                if (chart[i][j]&&!book[j])
                    m++;
            }
            if (m>=k)
                break;

            int ok = 1;
            que[cur] = i;

            for (int j = 0;j<cur;j++)
            {
                if (chart[que[i]][j])
                {
                    int w = cur-j;
                    if (w>=k)
                    {
                        ok = 0;
                        break;
                    }
                    if (w > now)
                        now = w;
                }
            }
            if (ok)
            {
                book[i] = 1;
                dfs(cur+1,now);
                book[i] = 0;
            }
            else
                break;
        }

    }
}

void handle_letter()
{
    int w = 0;
    for (char c = 'A';c <= 'Z';c++)
        if (find(s.begin(),s.end(),c)-s.begin() != s.length())
        {
            data[c] = w;
            letter[w] = c;
            w++;
            k++;
            len++;
        }
}

void handle_string()
{
    int ad = 0,flag = 0;
    char head;
    while(ad < s.length())
    {
        if (isalpha(s[ad]) && flag == 0)
        {
            head = s[ad];
            flag = 1;
            ad+=2;
        }
        else if (isalpha(s[ad]) && flag)
        {
            chart[data[head]][data[s[ad]]] = 1;
            chart[data[s[ad]]][data[head]] = 1;
            ad++;
        }
        else if (s[ad] == ';')
        {
            flag = 0;
            ad++;
        }
    }
}
