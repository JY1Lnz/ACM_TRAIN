#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> zero;
        vector<int> seq;
        set<vector<int> > data;
        int n,a;
        cin>>n;
        int flag = 0;
        while(n--)
        {
            cin>>a;
            seq.push_back(a);
            zero.push_back(0);
        }
        data.insert(seq);
        while(1)
        {
            if (seq == zero)
            {
                flag = 1;
                break;
            }

            int a0 = seq[0];
            for (int i = 0;i<seq.size()-1;i++)
                seq[i] = abs(seq[i] - seq[i+1]);
            seq[seq.size()-1] = abs(a0-seq[seq.size()-1]);

            if (data.count(seq) != 0)
            {
                flag = 2;
                break;
            }
            data.insert(seq);
        }
        if (flag == 1)
            cout<<"ZERO\n";
        else if (flag == 2)
            cout<<"LOOP\n";


    }

    return 0;
}
