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
        int n; cin >> n;
        vector<int> a(n); 
        for(int i = 0; i < n; i++) cin >> a[i];
        
        int ans = 0;
        for(auto &el : a) ans += el;
        cout << ans << endl;
    }
}
