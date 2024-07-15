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
vector<int> adj[N], v, xx(N);
vector<pair<int, int>> ok(N);
map<int, int> mp;

void dfs(int n, int p){
    for(auto &i : adj[n]){
        if(i == p) continue;

        ok[v[i]].first = 1;
        dfs(i, n);

        if(ok[v[i]].first == 1){
            xx[v[i]]++;
            ok[v[i]].first = 0;
        }
    }

    if(adj[n].size() == 1){
        if(ok[v[n]].first == 1){
            xx[v[n]]++;
            ok[v[n]].first = 0;
        }
    }
}
 
signed main(){
    IO();

    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        v = vector<int>(n + 1);

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            xx[i] = 0;
            ok[i].first = ok[i].second = 0;
        }

        for(int i = 1; i <= n; i++) cin >> v[i];

        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(n == 1) {
            cout << 1 << endl;
            return 0;
        }

        ok[v[1]] = {1, 1};
        xx[v[1]] = 0;

        dfs(1, -1);
        int ans = 0;

        for(int i = 1; i <= n; i++){
            ans += xx[i];
        }
        if(xx[v[1]] == 0) ans++;
        cout << ans << endl;
    }
}
