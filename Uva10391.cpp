#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    set<string> data;
    while(cin>>s)
    {
        data.insert(s);
    }

    for (auto ss:data)
    {
        for (int i = 1;i<=ss.length();i++)
        {
            string l(ss,0,i);
            string r(ss,i,ss.length());
            if (data.count(l)&&data.count(r))
            {
                cout<<ss<<endl;
                break;
            }
        }
    }

    return 0;
}
