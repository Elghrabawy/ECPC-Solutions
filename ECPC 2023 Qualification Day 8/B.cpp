#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int INF = 1e15, MOD = 1e9 + 7;
 
signed main(){
    IO();

    int n; cin >> n;
    cout << n / 2 << " " << (n + 1) / 2 << endl;
}
