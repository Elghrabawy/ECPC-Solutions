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
        int n; cin >> n;
        vector<int> a(n); for(auto &el : a) cin >> el;

        int _xor = 0;
        for(auto &el : a) _xor ^= el;
        set<int> st[32];
        for(int i = 0; i < n; i++){
            for(int b = 0; b < 32; b++){
                if(a[i] & (1 << b)){
                    st[b].insert(i);
                }
            }
        }

        while(true){
            // *Me
            if(_xor == 0){
                cout << "0 0" << endl;
                cout.flush();
            }
            else{
                int idx = *st[__lg(_xor)].begin();

                for(int i = 0; i < 32; i++){
                    if(a[idx] & (1 << i)){
                        st[i].erase(idx);
                    }
                }

                cout << idx + 1 << ' ' << a[idx] - (_xor ^ a[idx]) << endl;
                cout.flush();
                a[idx] = _xor ^ a[idx];

                for(int i = 0; i < 32; i++){
                    if(a[idx] & (1 << i)){
                        st[i].insert(idx);
                    }
                }
                _xor = 0;
            }
            
            // *Instructor
            int idx, rem; cin >> idx >> rem;
            if(idx == 0) break;

            idx--;
            for(int i = 0; i < 32; i++){
                if(a[idx] & (1 << i)){
                    st[i].erase(idx);
                }
            } 

            _xor ^= a[idx];
            a[idx] -= rem;
            _xor ^= a[idx];

            for(int i = 0; i < 32; i++){
                if(a[idx] & (1 << i)){
                    st[i].insert(idx);
                }
            }
        }
    }
}
