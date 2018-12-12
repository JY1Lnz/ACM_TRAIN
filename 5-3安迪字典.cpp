#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string> data;
    string s,buf;
    while(cin>>s)
    {
        for (int i = 0;i<s.length();i++)
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        stringstream ss(s);
        while(ss>>buf)
            data.insert(buf);
    }
    for (set<string>::iterator it = data.begin();it != data.end();it++)
        cout<<*it<<'\n';


    return 0;
}
