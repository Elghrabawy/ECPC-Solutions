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

int seq_sum(int a, int c){
    return (c * (2 * a + (c - 1) * a)) / 2;
}

int digits(int num) {
    int ret = 0;
    while(num != 0) {
        num /= 10;
        ret++;
    }
    return ret;
}

signed main() {
    IO();

    int t; cin >> t;
    while(t--) {
        int l, r; cin >> l >> r;
        if(digits(l) == digits(r)) {
            cout << (r - l + 1) * digits(l) << endl;
            continue; 
        }

        int st = 1;
        while(st < l) {
            st *= 10;
        }

        int ans = (st - l) * digits(l);
        l = st;
        while(st < r) {
            st *= 10;
            st = min(st, r);
            ans += (st - l) * digits(l);
            l = st;
        }

        cout << ans + (r - st + 1) * digits(st) << endl;
    }
}