#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

int power(int a, int b){
    if(b == 0) return 1;
    int res = power(a*a, b/2);
    if(b % 2) res *= a;
    return res;
}

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a  >> b;

        if(a == 1){
            cout << (b * (b - 1LL)) / 2LL << endl;
            continue;
        }
        else{
            int r = 0;
            vector<int> prf(40, 0);
            prf[0] = 1;
    
            int i = 1;
            for(; prf[i - 1] < b ; i++)
                prf[i] += prf[i - 1] + power(a, i);

            r = i - 1;

            int ans = 0;
            for(int i = 0; i <= r; i++){
                if(prf[i] <= b) ans = i;
            }

            int tl = 1;
            for(int i = 1; i <= ans; i++) tl += i * power(a, i);
    
            int ret = (tl - 1) + (b - prf[ans]) * (ans + 1);
            cout << ret << endl;
        }
    }
}
