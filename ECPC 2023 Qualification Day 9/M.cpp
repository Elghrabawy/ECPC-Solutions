#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int N = 1e4 + 1, INF = 1e15;

int n, T; 
vector<vector<vector<vector<int>>>> ndis;
vector<vector<vector<int>>> cost(51, vector<vector<int>> (51, vector<int> (N)));
vector<vector<int>> adj, dis;
vector<int> c, cntC, finalcost;

void floyd() {
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= T; j++) {
            for(int k = 1; k <= T; k++) {
                if(dis[j][i] != INF && dis[i][k] != INF)
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
}
 
void newfloyd(vector<vector<int>> &d, int u, int v) {
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= T; j++) {
 
            d[i][j] = min(d[i][j], d[i][u] + d[v][j]);
            d[i][j] = min(d[i][j], d[j][u] + d[v][i]);
        }
    }
}

int dfs(int u, vector<vector<int>> &d, vector<int> &cs){
    int ret = 0;
 
    for(auto &v : adj[u]){
        ret += d[c[u]][c[v]] * cntC[v] + d[c[u]][c[v]] + dfs(v, d, cs);
    }
 
    finalcost[u] = min(finalcost[u], ret);
    return ret;
}
 
int cntChildren(int u){
    int &ret = cntC[u];
    for(auto &v : adj[u]){
        ret += cntChildren(v) + 1;
    }
    return ret;
}

signed main(){
    IO();
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
 
        finalcost = vector<int> (n + 1, INF);
        cntC = vector<int> (n + 1);
        adj = vector<vector<int>> (n + 1);
        c = vector<int> (2);    
        dis = vector<vector<int>> (51, vector<int> (51));
 
        T = 0;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= 50; i++) for(int j = 1; j <= 50; j++) dis[i][j] = (i == j ? 0 : INF);
        for(int i = 2; i <= n; i++) {
            int x; cin >> x;
            adj[x].push_back(i);
        }
 
        map<string, int> id;
        id["pink"] = ++T;
 
        c[1] = 1;
        for(int i = 2; i <= n; i++) {
            string s; cin >> s;
            if(!id[s]) id[s] = ++T;
            c.push_back(id[s]);
        }
      
        ndis = vector<vector<vector<vector<int>>>> (T + 1, vector<vector<vector<int>>> (T + 1, vector<vector<int>> (T + 1, vector<int> (T + 1))));
 
        int q; cin >> q;
        while(q--) {
            string a, b;
            cin >> a >> b;
            int w; cin >> w;
 
            int aa = id[a], bb = id[b];
            dis[aa][bb] = min(dis[aa][bb], w);
            dis[bb][aa] = min(dis[bb][aa], w);
        }
 
        floyd();
        cntChildren(1);
 
        for(int i = 1; i <= T; i++) {
            for(int j = i + 1; j <= T; j++) {
                ndis[i][j] = dis;
                newfloyd(ndis[i][j], i, j);
                ndis[j][i] = ndis[i][j];
 
                dfs(1, ndis[i][j], cost[i][j]);
 
                cost[j][i] = cost[i][j];
            }
        }
 
        cin >> q;
        while(q--) {
            int x; cin >> x;
            cout << finalcost[x] << endl;
        }
    }
}