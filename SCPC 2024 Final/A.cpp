#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int total = 49 * x * x - ((49 * x * x) / 2 + 4 * x * x);
        cout << max(0LL, n - total / 14) << endl;
    }
}
