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

const int N = 11, K = 16;
int n, m, k;
double dp[N][K]; 
vector<int> adj[N];
 
double solve(int u, int rem){
    if(u == n) return 1;
    if(rem == 0) return 0;
 
    double &sums = dp[u][rem];
    if(sums != -1) return sums;
 
    double nbors = adj[u].size();
    sums = 0;
 
    for(auto &v : adj[u]){
        sums += solve(v, rem - 1) * (1.0 / nbors);
    }
    return sums;
}

signed main(){
    IO();

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            dp[i][j] = -1;
        }
    }
    
    cout << fixed << setprecision(10) << solve(1, k) << endl;
}
