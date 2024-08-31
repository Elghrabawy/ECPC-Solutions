#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin) , freopen("../output.txt", "w", stdout);
    #endif
}

#define int long long

const int MOD = 1e9 + 7;

int modSum(int a, int b, int mod) {
    return ((a % mod) + (b % mod)) % mod;
}
 
int modMul(int a, int b, int mod) {
    return ((a % mod) * (b % mod)) % mod;
}
 
int modSub(int a, int b, int mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}
 
int modExp(int a, int b, int mod) {
    if (b <= 0) return 1;
    int ret = modExp(a * a % mod, b / 2, mod);
    if (b % 2) ret = ret * a % mod;
    return ret;
}
 
signed main(){
    IO();

    int t; cin >> t;
    while(t--) {
        int n, s, m;
        cin >> n >> s >> m;
        if(n & 1) cout << modSub(modExp(2, s, MOD), 1, MOD) << endl;
        else {
            int ans = modSub(modExp(2, s, MOD), 1, MOD);
            if(m == s) {
                cout << 0 << endl;
                continue;
            }
 
            ans = modSub(ans, modSub(modExp(2, s - (s - m) * n, MOD), 1, MOD), MOD);
            cout << ans << endl;
        }
    }
}