#include<bits/stdc++.h>
using namespace std;

int book[10];

bool getsum(int n,int m)
{
    ostringstream oss;
    oss<<n;
    oss<<m;
    string s = oss.str();
    int flag0 = 0;
    for (int i = 0;i<s.length();i++)
    {
        if (s[i]-'0' == 0)
            flag0 = 1;
        if (book[s[i]-'0'] == 1)
            return false;
        book[s[i]-'0'] = 1;
    }
    if (book[0] == 0&&s.length() == 9)
        return true;
    else if (s.length() != 10)
        return false;
    return true;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if (n == 0)
            break;
        for (int i = 01234;i<=98765;i++)
        {
            memset(book,0,sizeof(book));
            int other = i/n;
            if (other<01234)
                continue;
            if (other > 98765)
                break;
            if (other*n != i)
                continue;
            if (getsum(other,i))
                printf("%05d / %05d = %d\n",i,other,n);
        }
    }

    return 0;
}
