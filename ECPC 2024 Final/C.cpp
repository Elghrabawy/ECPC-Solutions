#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define ld long double

signed main(){
    IO();

    int t; cin >> t; 
    while(t--){
        ld a, b, c; cin >> a >> b >> c;
 
        cout << fixed << setprecision(10);
        if(c != 0) cout << -1 << endl;
        else cout << a / 2.0 << " " << b / 2.0 << endl;
    }
}
