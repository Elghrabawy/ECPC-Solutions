#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 1, INF = 1e15, MOD = 1e9 + 7;
 
void dijkstra(int node, stack<int> &st, vector<int> &dis, vector<vector<pair<int, int>>> &adj) {
    dis[node] = 0;
 
    while(!st.empty()) {
        int u = st.top();
        st.pop();
 
        if(dis[u] != -INF) {
            for(auto edge : adj[u]) {
                int v = edge.first;
                int len = edge.second;
                
                if(dis[u] + len > dis[v]) dis[v] = dis[u] + len;
            }
        }
    }
}

bool visited[N];
void dfs(int node, vector<vector<pair<int, int>>> &adj, stack<int> &st) {
    visited[node] = 1;
    for(auto edge : adj[node]) {
        if(!visited[edge.first]) {
            dfs(edge.first, adj, st);
        }
    }
    st.push(node);
}

signed main(){
    IO();

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>> ());
    vector<vector<pair<int, int>>> radj(n + 1, vector<pair<int, int>> ());
    
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }
 
    vector<int> dis(n + 1, -INF), rdis(n + 1, -INF);
    stack<int> st1, st2;
    dfs(1, adj, st1);
    for(int i = 1; i <= n; i++) visited[i] = 0;
    dfs(n, radj, st2);
    dijkstra(1, st1, dis, adj);
    dijkstra(n, st2, rdis, radj);
 
    while(q--) {
        int u;
        cin >> u;
        cout << (dis[u] == -INF || rdis[u] == -INF ? -1 : dis[u] + rdis[u]) << endl;
    }
}
