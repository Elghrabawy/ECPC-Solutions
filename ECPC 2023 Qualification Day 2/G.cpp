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

signed main() {
    IO();

    int t = 1; 
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        map<int, int> mp;
        for(auto &c : s) mp[c]++;

        int mx = 0;
        for(auto &[c, freq] : mp){
            mx = max(mx, freq);
        }
        int ans=0;
        int l = 0, r = 1e10;
        while(l <= r){
            int mid = (l + r) / 2;

            if(mx + mid > (s.size() + mid) / 2){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
}