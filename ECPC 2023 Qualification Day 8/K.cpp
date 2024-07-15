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

const int INF = 1e15, MOD = 1e9 + 7;

int sum(int n){
    return (n * (n + 1)) / 2;
}
 
int takd_sec(int k){
    int l = 0, r = 2000000000LL;
    int maybe = 0;
 
    while(l <= r){
        int mid = (l + r) / 2;
        int value = (mid * (mid + 1)) / 2;
        if(value < k){
            l = mid + 1;
        }
        else if(value > k){
            r = mid - 1;
            maybe = mid;
        }
        else{
            return mid;
        }
    }
    return maybe;
}

signed main(){
    IO();

    int n; cin >> n;
    vector<int> a(n);
    for(auto &el : a) cin >> el;
    sort(all(a));
 
    vector<int> cnt(n + 1), prf(n + 1);
    for(int i = 0; i < n; i++){
        int instant = a[i] - (i > 0 ? a[i - 1] : 0) - 1;
        cnt[i + 1] = sum(instant);
        prf[i + 1] = prf[i] + cnt[i + 1];
    }
 
 
    int q, x; cin >> q >> x;
    if(q == 1){
        auto it = lower_bound(all(prf), x);
 
        int idx = it - prf.begin() - 1; // start from idx with a[idx - 1] sec
        int have_sec = (idx > 0 ? a[idx - 1] : 0);
        int req = x - prf[(idx >= 0 ? idx : 0)];
 
        int sec = have_sec + takd_sec(req);
        cout << sec << endl;
    }
    else{
        auto it = upper_bound(all(a), x);
        int idx = it - a.begin() - 1;
 
        int dis = prf[idx + 1 >= 0 ? idx + 1 : 0] +  sum(x - (idx >= 0 ? a[idx] : 0));
        cout << dis << endl;
    }
}
