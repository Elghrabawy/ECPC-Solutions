#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("fileIO/input.txt", "r", stdin);
        freopen("fileIO/output.txt", "w", stdout);
    #endif
}

const int INF = 1e15, N = 1e6 + 1;

signed main() {
    IO();

    vector<int> dp(N + 1, INF);
    dp[0] = dp[1] = 0;

    for(int i = 1; i <= N; i++){
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for(int j = i + i; j <= N; j += i){
            dp[j] = min(dp[j], dp[i] + j / i);
        }
    }

    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        int cost = 0;
        while(n--){
            int x; cin >> x;
            cost += dp[x];
        }
        cout << cost << endl;
    }
}