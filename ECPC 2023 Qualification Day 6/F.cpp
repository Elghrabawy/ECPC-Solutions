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

const int N = 1e5 + 1, INF = 1e15, MOD = 1e9 + 7;
 
signed main(){
    IO();

    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        int ans = 0;
        mp[s[0]]--;
        for(int i = 1; i < s.size(); i++){
            ans += mp[s[i]];
            mp[s[i]]--;
        }
        cout << ans << endl;
    }
}