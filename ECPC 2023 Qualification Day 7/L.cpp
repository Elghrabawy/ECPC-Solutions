#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

int main(){
    IO();
    
    int t = 1; cin >> t;
    while(t--){
        string s, k; cin >> s >> k;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != k[i]) ans++;
        }
        cout << ans << endl;
    }
}
