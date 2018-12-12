#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        queue<int> data;
        for (int i = 1;i<=n;i++)
            data.push(i);
        if (data.size() == 1)
        {
            cout<<"Discarded cards:"<<endl;
            cout<<"Remaining card: "<<data.front()<<endl;
            continue;
        }
        cout<<"Discarded cards: "<<data.front();
        data.pop();
        while(data.size() > 1)
        {
            data.push(data.front());
            data.pop();
            cout<<", "<<data.front();
            data.pop();
        }
        cout<<endl<<"Remaining card: "<<data.front()<<endl;
    }

    return 0;
}
