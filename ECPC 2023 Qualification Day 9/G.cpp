#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

signed main(){
    IO();

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &it : a) cin >> it;
    for(auto &it : b) cin >> it;
 
    for(int i = 0; i < n; i++) {
        int x = a[i];
        cout << (x % 2 == 0 ? 1 : 2) << ' ' << ((i + 1 + x) % n == 0 ? n : (i + 1 + x) % n) << endl;
    }
    for(int i = 0; i < n; i++) {
        int x = b[i];
        cout << (x % 2 == 0 ? 2 : 1) << ' ' << ((i + 1 + x) % n == 0 ? n : (i + 1 + x) % n) << endl;
    }
}
