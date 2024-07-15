#include <bits/stdc++.h>
using namespace std;

#define int long long 

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

int sum_digits(int n){
    int ret = 0;
    while(n){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

signed main() {
    IO();

    int t = 1; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;

        int st = l, en = r;
        while(st % 10) st++;
        while(en % 10) en--;

        int ans = ((en - st) / 10) * 5;
        
        for(int i = l; i < st; i++)
            ans += sum_digits(i) % 2;
        for(int i = en; i <= r; i++)
            ans += sum_digits(i) % 2;

        cout << ans << endl;
    }
}