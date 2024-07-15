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

const int INF = 1e15, MOD = 1e9 + 7;
 
signed main(){
    IO();

    int n, x; cin >> n >> x;
    vector<int> p(n - 1), v(n), sum(n + 1, -1), nearest(n + 1, -1); 
    for(auto &el : p) cin >> el;
    for(auto &el : v) cin >> el;
 
    vector<int> adj[n + 1];
    for(int u = 2; u <= n; u++){
        adj[p[u - 2]].push_back(u);
    }
 
    function<int(int)> build_sum = [&](int u)-> int{
        int &ret = sum[u];
        if(~ret) return ret;
 
        ret = v[u - 1];
 
        for(auto &v : adj[u]){
            ret += build_sum(v);
        }
        return ret;
    };
 
    nearest[1] = 1;
    function<void(int, int)> build_ancestors = [&](int u, int last)->void{
        nearest[u] = last;
 
        if(sum[u] >= x) last = u;
        for(auto &v : adj[u]){
            build_ancestors(v, last);
        }
    };
 
    build_sum(1);
    build_ancestors(1, 1);

    for(int u = 2; u <= n; u++){
        cout << nearest[u] << " ";
    }
}
