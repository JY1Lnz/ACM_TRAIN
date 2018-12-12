#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int num;
    Node * left;
    Node * right;
    Node():num(0),left(NULL),right(NULL){};
};

Node * newnode() {return new Node();}

int main()
{
    string s = "1 2 3";
    istringstream iss(s);
    int a;
    while(iss>>a)
    {
        cout<<a<<endl;
    }

    return 0;
}
