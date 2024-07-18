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

const int N = 1e5 + 5, INF = 1e15;
int n, m, l, k, dp[N], arr[N], vis[N];

int solve(int i){
    if(vis[i]) return dp[i];
    vis[i] = 1;

    int &ret = dp[i];
    
    return ret = max(
        ((i + n <= l + 1) ? solve(i + n) + arr[i + n] : 0),
        ((i - m >= 0) ? solve(i - m) + arr[i - m] : 0)
    );
}

signed main(){
    IO();

    cin >> l >> k >> n >> m;
    memset(dp, -1, sizeof(dp));

    for(int i = 0, tmp; i < k; i++){
        cin >> tmp; arr[tmp]++;
    }
    cout << solve(0) << endl;
}
