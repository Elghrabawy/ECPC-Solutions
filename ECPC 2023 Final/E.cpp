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
        int n, m; cin >> n >> m;
        vector<int> a(m); for(auto &el : a) cin >> el;
    
        bool in[n + 1] = {0};
        for(auto &el : a) in[el] = 1;
    
        bool is = true;
        for(int i = 1; i < a[0]; i++){
            if(in[i] == 0){
                is = false;
                break;
            }
        }
    
        if(is){
            cout << "Yes" << endl;
            for(int i = 1; i <= n; i++){
                if(in[i] == 0) cout << i << " ";
            }
            for(int i = 0; i < m; i++){
                cout << a[i] << (i < m - 1 ? " " : "");
            }
            cout << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}
