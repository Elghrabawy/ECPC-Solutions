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
        int a, b;
        cin >> a >> b;
        if(a == 1 || b == 1 || (b == 2 && (a & 1))) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
