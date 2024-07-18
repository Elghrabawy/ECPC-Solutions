#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int N = 1e3 + 9;
int n, m, ans;
vector<vector<char>> arr;
vector<vector<bool>> vis;
vector<vector<int>> dis;

bool valid(int i, int j){
    return (i < n && j < m && i >= 0 && j >= 0);
}

void dfs(int i, int j){
    if(!valid(i, j) || vis[i][j] || arr[i][j] == '#') return;

    char k = arr[i][j];

    arr[i][j] = '#', vis[i][j] = true;

    int a = (k == '.' || k == 'P' ? 1 : k - '0');
  
    dfs(i + a, j + a);
    dfs(i - a, j + a);
    dfs(i, j + a);
}

void bfs(){
    queue<pair<int, pair<int, int>>> q;
    for(int i = 0; i < n; i++){
        if(arr[i][0] != '#'){
            q.push({0, {i, 0}}), dis[i][0] = 0;
        }
    }

    while(!q.empty()){
        int d = q.front().first;
        int i = q.front().second.first, j = q.front().second.second;
        q.pop();

        int s; 
        if(valid(i, j) && arr[i][j] != '#'){
            if(arr[i][j] == '.') s = 1;
            else s = arr[i][j] - '0';

            if(valid(i + s, j + s) && (dis[i + s][j + s] > dis[i][j] + 1)){
                dis[i + s][j + s] = dis[i][j] + 1, q.push({dis[i + s][j + s], {i + s,j + s}});
            }
            if(valid(i, j + s) && (dis[i][j + s] > dis[i][j] + 1)){
                dis[i][j + s] = dis[i][j] + 1, q.push({dis[i][j + s], {i, j + s}});
            }
            if(valid(i - s, j + s) && (dis[i - s][j + s] > dis[i][j] + 1)){
                dis[i - s][j + s] = dis[i][j] + 1, q.push({dis[i - s][j + s], {i - s, j + s}});
            }
        }
    } 
}

signed main(){
    IO();
    cin >> n >> m;

    arr = vector<vector<char>> (n + 1, vector<char>(m + 1));
    vis = vector<vector<bool>> (n + 1, vector<bool>(m + 1, false));
    dis = vector<vector<int>> (n + 1, vector<int>(m + 1, INT64_MAX));

    vector<pair<int, int>> g;
    ans = INT64_MAX;
    for(int i = 0; i < n; i++){
        for(int j =0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'P') g.push_back({i, j});
        }
    }

    for(auto &i : g) dfs(i.first, i.second);
    bfs();
    
    for(int i = 0; i < n; i++) ans = min(ans, dis[i][m - 1]);
    if(ans == INT64_MAX) cout << -1 << endl;
    else cout << ans << endl;
}
