#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

signed main(){
    IO();

    int t; cin >> t;
    while(t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int ans = 0;
 
        while(n / 2 >= m && n != m) {
            if(b * (n - (n / 2)) < a) {
                ans += b * (n - (n / 2));
            }
            else {
                ans += a;
            }
 
            n /= 2;
        }
 
        ans += b * (n - m);
        cout << ans << endl;
    }
}