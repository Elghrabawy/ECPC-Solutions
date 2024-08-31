#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

signed main(){
    IO();

    int a, b; cin >> a >> b;
    cout << (a > b ? "p2" : (a < b ? "p1" : "d")) << endl;
}
