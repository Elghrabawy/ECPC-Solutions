#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

namespace __bridges{
    vector<pair<int, int>> bridges;
    vector<vector<int>> adj;
    vector<int> low, dfn;
    int ndfn, comps;

    void art_bridges(int u, int par) {
        low[u] = dfn[u] = ndfn++;

        for(auto &v : adj[u]) {
            if (dfn[v] == -1) {
                art_bridges(v, u);
                low[u] = min(low[u], low[v]);

                if(low[v] == dfn[v])
                    bridges.push_back({min(u, v), max(u, v)});
            } else if (v != par)
                low[u] = min(low[u], dfn[v]);
        }
    }
    void run_art_bridges() {
        int n = sz(adj);

        low.clear(), dfn.clear(), bridges.clear();
        low = dfn = vector<int>(n, -1);
        ndfn = comps = 0;

        for(int i = 0; i < n; i++) 
            if (dfn[i] == -1) art_bridges(i, -1), comps++;
        sort(all(bridges));
    }
} using namespace __bridges;

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int n, m, x; cin >> n >> m >> x;
        adj = vector<vector<int>>(n);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        run_art_bridges();
        if(comps > x) cout << -1 << endl;
        else{
            int total = x - comps;
            int a = min(sz(bridges), total), b = total - a;
            cout << total << endl << a << ' ' << b << endl;
        }
    }
}
