#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

signed main(){
    IO();
    
    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;

        int ans = INT_MAX;
        if(d == 0){
            cout << "Yes\n0" << endl;
            continue;
        }
        for(int x = -3e4; x <= 3e4; x++){
            if(a * x * x * x + b * x * x + c * x + d == 0){
                ans = x;
                break;
            }
        }

        if(ans == INT_MAX) cout << "No" << endl;
        else cout << "Yes\n" << ans << endl;
    }
}
