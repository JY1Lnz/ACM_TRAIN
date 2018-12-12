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
    char s[100] = "abc";
    cout<<strcmp(s,"ab");

    return 0;
}
