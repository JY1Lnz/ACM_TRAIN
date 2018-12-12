#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    while(cin>>a)
    {
    string s = "0";
    s += a;
    int next[s.length()] = {0};
    int last,cur;
    last = cur = 0;
    //cout<<s<<endl;
    for (int i = 1;i<=s.length()-1;i++)
    {
        if (s[i] == '[')
            cur = 0;
        else if (s[i] == ']')
            cur = last;
        else
        {
            next[i] = next[cur];
            next[cur] = i;
            if (last == cur)
                last = i;
            cur = i;
        }
    }
    for (int i = next[0];i != 0;i = next[i])
    {
        printf("%c",s[i]);
    }
    printf("\n");
    }

    return 0;
}
/*
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University

*/
