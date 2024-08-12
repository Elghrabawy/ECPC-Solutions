#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

#define int long long

signed main(){
    IO();

    int n, x, h, m, s; cin >> n >> x >> h >> m >> s;

    int droped = (h * 60 * 60 + m * 60 + s) * x;
    cout << max(0LL, n - droped) << endl;
}
