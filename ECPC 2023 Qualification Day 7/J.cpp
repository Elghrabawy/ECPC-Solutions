#include <bits/stdc++.h>
using namespace std;

#define all(a)   a.begin(),a.end()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

int main(){
    IO();
    
    int n, q; cin >> n >> q;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    while(q--){
        string query; cin >> query;
        vector <string> st = s;
        vector <string> temp;

        for(int i = 0; i < 5; i++){
            char c = query[i];
            if(c == '?') continue;
            for(auto &ss : st){
                if(ss[i] == c) temp.push_back(ss);
            }   
            st = temp;
            temp.clear();
        }

        sort(all(st));
        for(auto &ans : st){
            cout << ans << endl;
        }
    }
}
