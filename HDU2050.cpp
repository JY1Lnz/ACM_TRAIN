#include<iostream>
using namespace std;


//2 4 7 11
//1 2 3 4
//
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l;
        cin>>n;
        l = n;
        n = n*2;
        int line1 = (n*(n+1))/2 + 1;
        cout<<line1-l*2<<endl;

    }

    return 0;
}
