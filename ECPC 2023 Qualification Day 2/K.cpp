#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("fileIO/input.txt", "r", stdin);
        freopen("fileIO/output.txt", "w", stdout);
    #endif
}

#define int long long

int primeFac(int n){ // count number of prime factors
    int ret = 0;
    while(n % 2 == 0){
        n /= 2;
        ret++;
    }
    for(int i = 3; i * i <= n; i+= 2){
        while(!(n % i)) {
            ret++;
            n /= i;
        }
    }
    if(n != 1) ret++;
    return ret;
}


signed main() {
    IO();

    int t = 1; // cin >> t;
    while(t--){
        vector<vector<int>> magic(16, vector<int>(1e5 + 1));

        for(int x = 1; x <= 16; x++){
            for(int i = 1; i <= 1e5; i++){
                magic[x - 1][i] = magic[x - 1][i - 1];
                magic[x - 1][i] += (primeFac(i) == x);
            }
        }

        int q; cin >> q;
        while(q--){
            int l, r, x; cin >> l >> r >> x;
            cout << magic[x - 1][r] - magic[x - 1][l - 1] << endl;
        }
    }
}