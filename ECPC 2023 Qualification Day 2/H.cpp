#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("fileIO/input.txt", "r", stdin);
        freopen("fileIO/output.txt", "w", stdout);
    #endif
}

int main() {
    IO();

    int t = 1; 
    cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}