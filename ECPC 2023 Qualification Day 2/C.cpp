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
#define vi vector<int>

const int INF = 1e15;

signed main(){
    IO();

    int t = 1; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        vi a(n);
        for (auto &el : a) cin >> el;
        map<int, int> idx;
        vector<int> value(n + 1);
        for (int i = 0; i < n; i++) value[i] = a[i];

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) idx[a[i]] = i;

        vi group(n);
        group[0] = 1;

        int cnt = 1;
        for (int i = 1; i < n; i++){
            if (a[i] - a[i - 1] <= d) group[i] = cnt;
            else{
                cnt++;
                group[i] = cnt;
            }
        }

        int q; cin >> q;
        while (q--){
            int l, r; cin >> l >> r;

            if (group[idx[value[l - 1]]] == group[idx[value[r - 1]]])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}