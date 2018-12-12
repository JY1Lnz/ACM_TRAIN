#include<bits/stdc++.h>
using namespace std;

bool solove(int & w)
{
    int W1,D1,W2,D2;
    bool B1 = true,B2 = true;
    cin>>W1>>D1>>W2>>D2;
    if (!W1) B1 = solove(W1);
    if (!W2) B2 = solove(W2);
    w = W1+W2;
    return B1&&B2&&(W1*D1 == W2*D2);
}

int main()
{
    int t,w;
    cin>>t;
    while(t--)
    {
        if (solove(w))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        if (t)
            cout<<endl;
    }
    return 0;
}
