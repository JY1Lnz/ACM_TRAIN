#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int G[110][110],n,m,a,b;
int vis[110],c[110], topo[110], t;

bool dfs(int u){
    cout<<u<<endl;
    vis[u] = -1; //表示正在访问
    for(int v=1; v<=n; ++v) if(G[u][v]){
            cout<<u<<' '<<v<<' '<<vis[v]<<endl;
        if(vis[v] == -1) return false; // 如果存在有向环，失败退出
        else if(!vis[v] && !dfs(v)) return false;
    }
    // 结束访问
    printf("%d",topo[0]);
            for(int i=1; i<n; ++i)
                printf(" %d",topo[i]);
            printf("\n");
    vis[u] = 1; topo[--t] = u;
    return true;
}

bool topoSort(){
    t = n;
    memset(vis, 0, sizeof(vis));
    for(int u=1; u<=n; ++u)
        if(!vis[u] && !dfs(u)) return false;
    return true;
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    // 注意输入那里的结束条件不能是 n&&m,因为m可能是0
    while(~scanf("%d %d",&n,&m) && n+m){
        memset(G, 0, sizeof(G));
        for(int i=0; i<m; ++i){
            scanf("%d %d",&a,&b);
            G[a][b] = 1;
        }
        if(topoSort()) {
            printf("%d",topo[0]);
            for(int i=1; i<n; ++i)
                printf(" %d",topo[i]);
            printf("\n");
        }
    }
    return 0;
}

