#include<bits/stdc++.h>
using namespace std;

// N
//W E
// S
//Entrance Goal
const int maxn = 10;

struct Node
{
    int r,c,dir;
    Node(int a = 0,int b = 0,int c = 0):r(a),c(b),dir(c){}
}p[maxn][maxn][4];
const char * dirs = "NESW";
const char * turns = "FLR";
int dir_id(char c)  {return strchr(dirs,c)-dirs;}
int turn_id(char c) {return strchr(turns,c)-turns;}
//找朝向和转向
bool has_edge[maxn][maxn][4][3];//能否转向
int d[maxn][maxn][4];
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

int r0,c0;//入口
int r1,c1;//开始走的起始点
int r2,c2;//出口
int dir;//开始走的方向



Node walk(const Node & u,int turn)
{
    int dir = u.dir;
    if (turn == 1)
        dir = (dir+3)%4;//左转 防止dir为负值
    if (turn == 2)
        dir = (dir+1)%4;//右转
    return Node(u.r+dr[dir],u.c+dc[dir],dir);
}

bool inside(int r,int c)
{
    return (r>0 && r<=9 && c>0 && c <= 9);
}

void print_ans(Node u)
{
    vector<Node> nodes;
    while(1)
    {
        nodes.push_back(u);
        if (d[u.r][u.c][u.dir] == 0)
            break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0,c0,dir));
    int cnt = 0;
    for (int i = nodes.size()-1;i>=0;i--)
    {
        if (cnt % 10 == 0)
            printf(" ");
        printf(" (%d,%d)",nodes[i].r,nodes[i].c);
        if (++cnt % 10 == 0)
            printf("\n");
    }
    if (nodes.size() % 10 != 0)
        printf("\n");
}

void solve()
{
    queue<Node> q;
    memset(d,-1,sizeof(d));
    Node u(r1,c1,dir);
    d[u.r][u.c][dir] = 0;
    q.push(u);
    int cnt = 0;
    while(!q.empty())
    {
        Node u = q.front();
        q.pop();
        if (u.r == r2&&u.c == c2)
        {
            print_ans(u);
            return;
        }
        for (int i = 0;i<3;i++)
        {
            Node v = walk(u,i);//下一个结点
            if (has_edge[u.r][u.c][u.dir][i] && inside(v.r,v.c) && d[v.r][v.c][v.dir] < 0)
            {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}

bool Input()
{
    memset(has_edge,0,sizeof(has_edge));
    string name;
    cin>>name;
    if (name == "END")
        return false;
    char ch;
    cin>>r0>>c0>>ch>>r2>>c2;
    dir = dir_id(ch);
    r1 = r0 + dr[dir];
    c1 = c0 + dc[dir];

    int x,y,dd,tt;
    while(cin>>x)
    {
        if (!x)
            break;
        cin>>y;
        string str;
        while(cin>>str)
        {
            if (str == "*")
                break;
            dd = dir_id(str[0]);
            for (int i = 1;i<str.length();i++)
                has_edge[x][y][dd][turn_id(str[i])] = true;
        }
    }
    cout<<name<<endl;
    return true;
}

int main()
{
    while(Input())
    {
        solve();
    }


    return 0;
}
