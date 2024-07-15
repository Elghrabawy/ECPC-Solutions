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

    int n, k; cin >> n >> k;
    map<int, int> L, R;
    while(k--){
        int l, r; cin >> l >> r;
        L[l]++, R[r]++;
    }
 
    vector<int> range(n + 1);
    int cur = 0;
    for(int i = 1; i <= n; i++){
        if(L[i]) cur += L[i];
        range[i] = cur;
        if(R[i]) cur -= R[i];
 
    }
 
    int mx = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(range[i]) cnt = 0;
        else {
            cnt++;
            mx = max(mx, cnt);
        }
    }
    cout << max(mx, cnt) << endl;
}
