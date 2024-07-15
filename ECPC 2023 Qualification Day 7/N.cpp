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

const int N = 1e5 + 5;
int n, m, p, s, e, ans;

vector<pair<int, int>> adj[N];
vector<int> dist(N, INT64_MAX), mxs(N, -1);

void dijkstra(int src){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;

    dist[src] = 0;
    q.push({0, {0, src}});
    while(!q.empty()){
        int cost = q.top().second.first;
        int node = q.top().second.second;

        int mx = q.top().first; q.pop();

        if(mx < mxs[node]) continue;
        if(node == e && cost <= p) ans = max(ans, mx);

        for(auto &[child, chcost] : adj[node]){
            if(dist[node] + chcost < p && chcost > mxs[child] || mxs[node] > mxs[child]){
                dist[child] = dist[node] + chcost;
                q.emplace(make_pair(max(mx, chcost), make_pair(dist[child], child)));
                mxs[child] = max(mx, max(chcost, mxs[node]));
            }
        }
    }
}

signed main(){
    IO();

    cin >> n >> m >> s >> e >> p;
    for(int i = 0; i < m; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].emplace_back(make_pair(v, c));
    }

    ans = -1;
    dijkstra(s);
    cout << ans << endl;
}
