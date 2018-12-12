#include<bits/stdc++.h>
using namespace std;

const int len = 32;
const int maxn = 1024+10;
char s[maxn];
int data[maxn][maxn],cnt;
//2 1
//3 4
void draw(string s,int & p,int c,int r,int len)
{
    char ch = s[p++];
    if (ch == 'p')
    {
        draw(s,p,c+len/2,r,len/2);//1
        draw(s,p,c,r,len/2);//2
        draw(s,p,c,r+len/2,len/2);//3
        draw(s,p,c+len/2,r+len/2,len/2);//4
    }
    else if (ch == 'f')
    {
        for (int i = c;i<c+len;i++)
            for (int j = r;j<r+len;j++)
                if (!data[i][j])
                {
                    data[i][j] = 1;
                    cnt++;
                }
    }
}

int main()
{
    int t,cas = 0;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        string s;
        memset(data,0,sizeof(data));
        for (int i = 0;i<2;i++)
        {
            cin>>s;
            int p = 0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cnt);
    }

    return 0;
}
