#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long
#define all(x) x.begin(), x.end()

bool pal(int l, int r, string &s){
    string forw = s.substr(l, r - l + 1), rev;
    reverse_copy(all(forw), back_inserter(rev));
 
    return (forw == rev);
}
bool is(int l, int r, vector<int> &a){
    int sum = 0, or_ = 0;
    for(int i = l; i <= r; i++){
        sum += a[i];
        or_ |= a[i];
    }
    return (or_ == sum);
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int len = 32; len >= 0; len--){
        for(int i = 0; i <= n - len; i++){
            if(pal(i, i + len - 1, s) && is(i, i + len - 1, a)){
                cout << len << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

signed main(){
    IO();

    int t; cin >> t;
    while(t--) solve();
}
