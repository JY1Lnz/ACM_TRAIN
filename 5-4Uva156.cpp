#include<bits/stdc++.h>
using namespace std;

string repr(const string &s)
    {
        string ans = s;
        for (int i = 0;i<ans.length();i++)
            ans[i] = tolower(ans[i]);
        sort(ans.begin(),ans.end());
        return ans;
    }

int main()
{
    vector<string> word;
    map<string,int> cnt;
    string s;

    while(cin>>s)
    {
        if (s == "#")
            break;
        word.push_back(s);
        string r = repr(s);
        if (!cnt.count(r))
            cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0;i<word.size();i++)
        if (cnt[repr(word[i])] == 1)
            ans.push_back(word[i]);
    sort (ans.begin(),ans.end());
    for (int i = 0;i<ans.size();i++)
        cout<<ans[i]<<'\n';


    return 0;
}
