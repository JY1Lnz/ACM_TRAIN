#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
char s[maxn];
bool failed;
vector<int> ans;

struct Node
{
    bool have_value;
    int v;
    Node * left;
    Node * right;
    Node():have_value(false),left(NULL),right(NULL){};
};

Node * newnode() {return new Node();}//�������½�������װΪ����
Node * root;

bool read_input();
void addnode(int v,char * s);
bool bfs(vector<int> & ans);//ans�洢�������
void remove_tree(Node * u);//ɾ����һ�ε�������ֹ�ڴ�й©

int main()
{
    while(read_input())
    {
        bool flag = bfs(ans);
        if (failed)
            cout<<"not complete\n";
        else if (flag)
        {
            cout<<ans[0];
            for (int i = 1;i<ans.size();i++)
                cout<<' '<<ans[i];
            cout<<endl;
        }
        else
            cout<<"not complete\n";
    }

    return 0;
}

void addnode(int v,char * s)
{
    int n = strlen(s);
    Node * u = root;
    for (int i = 0;i<n;i++)
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = newnode();
            u = u->left;
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = newnode();
            u = u->right;
        }
    if (u->have_value)
        failed = true;
    u->v = v;
    u->have_value = true;
}

bool read_input()
{
    remove_tree(root);
    root = newnode();
    failed = false;
    memset(s,0,sizeof(s));
    while(1)
    {
        if (scanf("%s", s) != 1)
            return false;
        if (!strcmp(s, "()"))//strcmp���Ϸ���0�������Ϸ���1
            break;
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}

bool bfs(vector<int> & ans)//ans�洢�������
{
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while(!q.empty())
    {
        Node * u = q.front();
        q.pop();
        if (!u->have_value)
            return false;
        ans.push_back(u->v);
        if (u->left != NULL)
            q.push(u->left);
        if (u->right != NULL)
            q.push(u->right);
    }
    return true;
}

void remove_tree(Node * u)
{
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}
