#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

const int N = 1e5 + 5, M = 1e9 + 7;

vector<vector<int>> rangeFactorization(int n){
    vector<vector<int>> divisors(n + 1);
    for(int i = 1; i <= n; i++){
        for(int k = i; k <= n; k += i){
            divisors[k].push_back(i);
        }
    }
    return divisors;
}

signed main(){
    IO();

    vector<vector<int>> divisors = rangeFactorization(100000);
    vector<int> frq(N, 0), total(N, 0), divs_aftr(N, 0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n); for(auto &el : a) cin >> el;

        for(int i = n - 1; i >= 0; i--){
            for(auto &x : divisors[a[i]]) divs_aftr[i] += frq[x];
            frq[a[i]]++;    
            total[a[i]] = ((total[a[i]] % M) + (divs_aftr[i] % M)) % M;
        }

        for(auto &el : a) frq[el] = 0; // reset frq array

        int ans = 0;
        for(int i = 0; i < n; i++){
            int divs_bfr = 0;
            for(auto &x : divisors[a[i]]) divs_bfr += frq[x];
            frq[a[i]]++;

            total[a[i]] = ((total[a[i]] % M) - (divs_aftr[i] % M) + M) % M;

            ans += ((divs_bfr % M) * (total[a[i]] % M)) % M;
            ans %= M;
        }

        cout << ans << endl;
        for(int i = 0; i < n; i++) divs_aftr[i] = frq[a[i]] = total[a[i]] = 0;
    }
}
