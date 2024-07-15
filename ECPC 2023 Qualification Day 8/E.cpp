#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int INF = 1e15, MOD = 1e9 + 7;
 
signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> o(n), m(n);
        for(auto &el : o) cin >> el;
        for(auto &el : m) cin >> el;
    
        long double totalo = 0, totalm = 0, likeo = 0, likem = 0;
        for(int i = 0; i < n; i++){
            if(o[i] && !m[i]) likeo++;
            if(!o[i] && m[i]) likem++;
            
            totalo += o[i], totalm += m[i];
        }
    
        cout << fixed << setprecision(10)
        << (totalo != 0 ? ((likeo * (long double)100) / totalo) : 0) 
        << " " 
        << (totalm != 0 ? ((likem * (long double)100) / totalm) : 0) 
        << endl;
    }
}
