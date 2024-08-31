#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

signed main(){
    IO();

    int t; cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        if(a & 1 && b & 1 && c & 1) ans++;
        ans += a / 2 + b / 2 + c / 2 + d / 2;
        cout << ans << endl;
    }
}
