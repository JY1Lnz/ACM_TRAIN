#include<bits/stdc++.h>
using namespace std;

struct Node//二叉树结点
{
    char value;
    bool have_value;
    Node * left;
    Node * right;
    Node():left(NULL),right(NULL),have_value(false){}
};

Node * newnode()//申请新结点
{
    return new Node();//new一个对象
}

Node * root;
string A,B;
int H;
void Solve(int L,int R,Node * root)
{
    int p = L;
    while(B[p] != A[H])
        p++;
    Node * u = root;
    u->value = A[H++];
    u->have_value = true;
    if (p > L)
    {
        u->left = newnode();
        Solve(L,p-1,u->left);
    }
    if (p < R)
    {
        u->right = newnode();
        Solve(p+1,R,u->right);
    }
    return;
}

void bianli_xianxu(Node * root)
{
    cout<<root->value;
    if (root->left != NULL)
        bianli_xianxu(root->left);
    if (root->right != NULL)
        bianli_xianxu(root->right);
}

void bianli_zhongxu(Node * root)
{
    if (root->left != NULL)
        bianli_zhongxu(root->left);
    cout<<root->value;
    if (root->right != NULL)
        bianli_zhongxu(root->right);
}

void bianli_houxu(Node * root)
{
    if (root->left != NULL)
        bianli_houxu(root->left);
    if (root->right != NULL)
        bianli_houxu(root->right);
    if (root->have_value)
        cout<<root->value;

}

int main()
{
    while(cin>>A>>B)
    {
        root = newnode();
        H = 0;
        Solve(0,A.length()-1,root);
        bianli_houxu(root);
        cout<<endl;
        bianli_zhongxu(root);
        cout<<endl;
    }


    return 0;
}
