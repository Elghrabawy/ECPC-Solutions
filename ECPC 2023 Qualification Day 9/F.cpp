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
    while(t--){
        int x, y; cin >> x >> y;
        cout << (x >= y ? "YES" : "NO") << endl;
    }
}
