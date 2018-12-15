#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        stack<char> data;
        getline(cin,s);
        for (int i = 0;i<s.length();i++)
        {
            char c = s[i];
            if (!data.empty()&&data.top() == '('&&c ==')')
                data.pop();
            else if (!data.empty()&&data.top() == '['&&c == ']')
                data.pop();
            else
                data.push(c);
        }

        if (data.empty())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}
