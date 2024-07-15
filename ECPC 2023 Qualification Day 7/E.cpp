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

const int N = 501;
int k, x, y, n, m, dp[2][N][N], dp_old[N][N], dp_cur[N][N];
vector<int> w, d;

signed main(){
    IO();

    cin >> k >> x >> y >> n >> m;
    d = w = vector<int>(k); 
    for(auto &el : w) cin >> el;
    for(auto &el : d) cin >> el;
 
    for(int i = 0; i < k; i++){
        for(int rem1 = 0; rem1 <= x; rem1++){
            for(int rem2 = 0; rem2 <= y; rem2++){
                dp_cur[rem1][rem2] = max({
                    rem1 >= w[i] + n ? dp_old[rem1 - (w[i] + n)][rem2] + d[i] : 0,
                    rem2 >= w[i] + m ? dp_old[rem1][rem2 - (w[i] + m)] + d[i] : 0,
                    dp_old[rem1][rem2]
                });
            }
        }
        swap(dp_cur, dp_old);
    }
    cout << dp_old[x][y] << endl;
}