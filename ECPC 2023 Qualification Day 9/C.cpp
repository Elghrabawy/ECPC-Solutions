#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)x.size()

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
        string s; cin >> s;
 
        int last = s[sz(s) - 1] - '0';
        if(sz(s) > 1) last += 10 * (s[sz(s) - 2] - '0');
    
        cout << (last % 4 ? 0 : 4) << endl;
    }
}
