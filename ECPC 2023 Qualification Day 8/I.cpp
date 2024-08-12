#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

#define int long long

const int N = 1e5 + 5, LOG = 23;
int anc[N][LOG], depth[N], sum[N];
vector<int> adj[N];

void build(int u, int par, int d){
    anc[u][0] = par, depth[u] = d;
    for(int i = 1; i < LOG; i++){
        int p = anc[u][i - 1];
        anc[u][i] = anc[p][i - 1];
    }

    for(auto &v : adj[u]){
        if(v != par){
            build(v, u, d + 1);
        }
    }
}
int kthAncestor(int u, int k){ // build(root, root)
    for(int i = 0; i < LOG; i++)
        if(k & (1 << i)) u = anc[u][i];
    return u;
}
int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    u = kthAncestor(u, depth[u] - depth[v]);
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--){
        if(anc[u][i] != anc[v][i]){
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}
int dis(int u, int v){
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

int dfs(int u, int par){
    for(auto &v : adj[u]){
        if(v != par){
            sum[u] += dfs(v, u);
        }
    }
    return sum[u];
}
 
signed main(){
    IO();

    int n, m; cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    build(1, 1, 0);
    
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        int lca = LCA(u, v);
        sum[u] += w, sum[v] += w, sum[lca] -= w;
        if(lca != 1) sum[kthAncestor(lca, 1)] -= w;
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) cout << sum[i] << ' ';
}