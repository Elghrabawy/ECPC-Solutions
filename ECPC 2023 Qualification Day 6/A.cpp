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

const int N = 1e5 + 1, INF = 1e15, MOD = 1e9 + 7;
 
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

    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
 
        cout << modSum(modSub(modExp(2, n + 1, MOD), modMul(2, modSum(n, 1, MOD), MOD), MOD), n, MOD) << endl;
    }
}
