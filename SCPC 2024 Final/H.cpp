#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long
 
const int M = 1e9 + 7, N = 4e3 + 1;
int dp[N][N][2][2], lcp[N][N], n;
string s;
 
int compare(int al, int ar, int bl, int br){
    int alen = ar - al + 1, blen = br - bl + 1;
    if(alen == blen){
        int l = 0, r = alen - 1;
        int _lcp =  lcp[al][bl];    
 
        if((_lcp + al) > ar) return 0;
        return (s[al + _lcp] > s[bl + _lcp] ? 1 : -1);
    }
    else return(alen > blen ? 1 : -1);
}
 
int solve(int i, int len, bool par, bool take_one){
    if(i >= n)  return take_one && par^1;
 
    int &ret = dp[i][len][par][take_one];
    if(~ret) return ret;
 
    ret = 0;
    int cmp = compare(i - len + 1, i, i + 1, i + len);
    if(i + len < n && (cmp == -1 || (cmp == 0 && par))){ // (ai < ai + 1) or (ai == ai + 1 i is odd)
        ret = (ret % M + solve(i + len, len, par ^ 1, 1) % M) % M;
    }
    else if(i + len + 1 < n){ 
        ret = (ret % M + solve(i + len + 1, len + 1, par ^ 1, 1) % M) % M;
    }
    ret = (ret % M + solve(i + 1, len + 1, par, take_one) % M) % M;
 
    return ret;
}

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        cin >> n >> s;
 
        for(int i = 0; i <= n; i++){ for(int j = 0; j <= n; j++){
            lcp[i][j] = -1;
            for(int k = 0; k < 2; k++){ for(int l = 0; l < 2; l++){
                dp[i][j][k][l] = -1;
            }}
        }}
    
    
        for(int i = n - 1; i >= 0; i--) for(int j = n - 1; j >= 0; j--)
            lcp[i][j] = (s[i] != s[j] ? 0 : 1 + lcp[i + 1][j + 1]);
    
        cout << solve(0, 1, 1, 0) << endl;
    }
}
