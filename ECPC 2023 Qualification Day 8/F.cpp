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
 
int sum(int n){
    return (n * (n + 1)) / 2;
}
signed main(){
    IO();

    int n, x, k; cin >> n >> x >> k;
    vector<int> a(n), b(x);
    for(auto &el : a) cin >> el;
    for(auto &el : b) cin >> el;

    map<int, int> have, need;
    for(auto &el : a) have[el]++;
    for(auto &el : b) need[el]++;
 
    int cost = 0;
    for(auto &[item, _] : need){
        cost += max(0LL, sum(need[item] - 1) - sum(have[item] - 1));
    }
    cout << (cost <= k ? "YES" : "NO") << endl;
}
