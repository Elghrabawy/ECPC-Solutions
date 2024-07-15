#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 1, INF = 1e15;

int dis[501][501];
vector<int> adj[N];
int x, n;
 
void bfs(int node) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    dis[node][node] = 0;
 
    while(!q.empty()) {
        int du = q.front().second;
        int u = q.front().first;
 
        for(int child : adj[u]) {
            if(dis[node][child] == INF) {
                dis[node][child] = du + 1;
                q.push({child, dis[node][child]});
            }
        }
 
        q.pop();
    }
}
 
int ceil(int a, int b) {
    return a / b + (a % b != 0);
}
 
signed main() {
    IO();
 
    int m;
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) dis[i][j] = INF;
    }
 
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int mx = -INF;
    for(int i = 1; i <= n; i++) {
        bfs(i);
        for(int j = 1; j <= n; j++) {
            mx = max(mx, dis[i][j]);
        }
    }
 
    int l = 1, r = 100000;
    int ans = 0;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
 
    while(l <= r) {
        int mid = l + (r - l) / 2;
 
        if(mid != 0 && ceil(mx, mid) <= x) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
 
    cout << ans << endl;
}