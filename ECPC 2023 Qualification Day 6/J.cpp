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
 
signed main(){
    IO();

    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            ans |= x;
        }
 
        bool bad = 0;
        for(int i = 0; i <= 32; i++) {
            if(((ans >> i) & 1) && !((k >> i) & 1)) bad = 1;
        }
 
        if(bad) {
            cout << -1 << endl;
            continue;
        }
 
        cout << (ans ^ k) << endl;
    }
}
