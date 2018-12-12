#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ifstream cin ("cin.in");
    string s;
    getline(cin,s);
    char op,w;
    cin>>op;
    //string v;
    if (op == 'D')
    {
        char v;
        cin>>v;
        int flag =1;
        for (int i = 0;i<s.length();i++)
        {
            if (flag&&s[i] == v)
                flag = 0;
            else
                cout<<s[i];
        }
        cout<<endl;
    }
    else if (op == 'I')
    {
        string v;
        cin>>w>>v;
        //int flag = 1;
        for (int i = s.length()-1;i>=0;i--)
        {
            if (s[i] == w)
            {
                s.insert(i,v);
                break;
            }
        }
        cout<<s<<endl;
    }
    else
    {
        char v;
        cin>>w>>v;
        for (int i = 0;i<s.length();i++)
            if(s[i] == w)
                cout<<v;
            else
                cout<<s[i];
        cout<<endl;
    }

    return 0;
}

