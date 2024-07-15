#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

bool can(int mid, vector<int> &a, int &n, int &k){
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (a[i] + mid - 1) / mid - 1; 
    return (cnt <= k);
}
 
signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(auto &el : a) cin >> el;

        int l = 1, r = 1e9, ans = -1;
        while(l <= r){
            int mid = l + (r - l + 1) / 2;
            if(can(mid, a, n, k)){
                r = mid - 1, ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
