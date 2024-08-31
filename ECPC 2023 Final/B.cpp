#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long
const int MAX = 1e9 + 7;

signed main(){
    IO();
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
    
        int mx_l = 0, cnt_mx = 1;
        int last = -1, l = 1;
        for(int i = 0; i < s.length(); i++){
            if(i == 0 || s[i] != s[i - 1]) mx_l++, cnt_mx *= l, cnt_mx %= MAX, l = 1;
            else l++;
        }
        cnt_mx = ((cnt_mx % MAX) * (l % MAX)) % MAX;
        
        cout << mx_l << " " << cnt_mx << endl;
    }
}
