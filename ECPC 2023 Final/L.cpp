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
        int n, k; cin >> n >> k;

        int mx = 2 * (n / 2) * ((n + 1) / 2);

        if(k % 2 || k > mx) cout << "No" << endl;
        else{
            cout << "Yes" << endl;
            vector<int> to(n + 1, 0);

            for(int i = 1; i <= n && k > 0; i++){
                if(to[i] == 0){
                    if(2 * ((n - i + 1) - i) >= k){
                        to[i] = i + k / 2, to[i + k / 2] = i;
                        k = 0;
                    }
                    else{
                        to[i] = n - i + 1, to[n - i + 1] = i;
                        k -= 2 * ((n - i + 1) - i);
                    }
                }
            }
            for(int i = 1; i <= n; i++){
                cout << (to[i] ? to[i] : i);
                if(i < n) cout << " ";
            }
            cout << endl;
        }
    }
}
