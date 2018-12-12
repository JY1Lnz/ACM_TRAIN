#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        int left[n],right[n];
        for (int i = 0;i<n;i++)
            cin>>left[i]>>right[i];
        sort(left,left+n);
        sort(right,right+n);
        int flag = 1;
        for (int i = 0;i<n;i++)
            if (left[i] != right[i])
            {
                flag = 0;
                break;
            }
        if (flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
