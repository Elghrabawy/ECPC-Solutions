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

int modSum(int a, int b, int n){
    return ((a % n) + (b % n)) % n;
}
int modMul(int a, int b, int n){
    return ((a % n) * (b % n)) % n;
}
int modSub(int a, int b, int n){
    return ((a % n) - (b % n) + n) % n;
}

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n); 
        for(auto &el : a) cin >> el;
        sort(all(a));
    
        int sum = 0, cnt = 0, ans = 0;
        for(auto &el : a){  
            ans = modSum(ans, modSub(modMul(cnt, el, m) ,sum, m), m);
            sum += el, cnt++;
            sum %= m;
            ans %= m;
        }
        cout << ans << endl;
    }
}
