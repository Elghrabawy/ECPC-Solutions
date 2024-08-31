#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

signed main(){
    IO();
    
    int a, b;
    cin >> a >> b;
    if(a >= 2500 && a - b < 2500) cout << "Yes" << endl;
    else cout << "No" << endl;
}
