#include<bits/stdc++.h>
using namespace std;
//大数
//递推没问题
const int maxn = 100+10;
long long dp[maxn][2];
int n,k,u;
vector<string> dp0;
vector<string> dp1;
string a,b;
string big_add(string a,string b)
{
    string s;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sum = 0;

    for (int i = 0;i<b.length();i++)
    {
        sum = (a[i]-'0')+(b[i]-'0')+sum;
        s += char(sum%10 + '0');
        sum/=10;
    }
    for (int i = b.length();i<a.length();i++)
    {
        sum = (a[i]-'0') + sum;
        s += char(sum%10 + '0');
        sum/=10;
    }
    while(sum > 0)
    {
        s += char(sum%10 + '0');
        sum/=10;
    }
    for (int i = s.length()-1;i>=0;i--)
        if (s[i] != '0')
            break;
        else
            s[i] = 0;
    reverse(s.begin(),s.end());
    return s;
}

string big_sub(string a,string b)//忽视正负问题
{
    string s;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int overflow = 0;
    for (int i = 0;i<b.length();i++)
    {
        a[i] = a[i] - overflow;
        if (a[i] < b[i])
        {
            overflow = 1;
            s += char((10-(b[i]-'0'))+(a[i]-'0')+'0');
        }
        else if (a[i] > b[i])
        {
            overflow = 0;
            s += char((a[i]-'0')-(b[i]-'0')+'0');
        }
        else
        {
            overflow = 0;
            s += '0';
        }
    }
    for (int i = b.length();i<a.length();i++)
    {
        a[i] = a[i] - overflow;
        if ((a[i]-'0') < 0)
        {
            overflow = 1;
            s += '9';
        }
        else
        {
            overflow = 0;
            s += a[i];
        }
    }
    for (int i = s.length()-1;i>=0;i--)
        if (s[i] != '0'||i == 0)
            break;
        else
            s.erase(i);
    reverse(s.begin(),s.end());
    return s;
}

string dp_string()
{
    dp0.resize(maxn,"");
    dp1.resize(maxn,"");
    dp0[0] = "1";
    dp1[0] = "0";
    string x = "1";
    for (int i = 1;i<=n;i++)
    {
        string sum = big_add(dp0[i-1],dp1[i-1]);
        //cout<<dp0[i-1]<<' '<<dp1[i-1]<<' '<<sum<<endl;
        dp0[i] = sum;
        if (i <= u)
            dp1[i] = sum;
        else if (i == u+1)
            dp1[i] = big_sub(sum,x);
        else if (i > u+1)
            dp1[i] = big_sub(sum,dp0[i-u-1]);
    }
    return big_add(dp0[n],dp1[n]);
}

int main()
{
    while(cin>>n>>k)
    {
        u = n;
        string all = dp_string();
        //cout<<all<<endl;
        u = k-1;
        string other = dp_string();
        //cout<<other<<endl;
        all = big_sub(all,other);
        int flag = 0;
        cout<<all<<endl;
        //all = "010203040";
    }
}
