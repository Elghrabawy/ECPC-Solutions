#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(a) (int)a.size()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if((a.second <= 0 && b.second > 0) || a.second > 0 && b.second <= 0) 
        return a.second > b.second;
    if(a.second <= 0 && b.second <= 0 && b.first != a.first) 
        return a.first > b.first;
    if(a.first > b.first || a.first < b.first) 
        return a.first < b.first;
    return a.second > b.second;
}
 
signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<int> suf_o(sz(s) + 1), suf_e(sz(s) + 1);

        for(int i = sz(s) - 1; i >= 0; i--){
            suf_o[i] += suf_o[i + 1];
            suf_e[i] += suf_e[i + 1];

            (i % 2 ? suf_o[i] : suf_e[i]) += s[i] - '0';
        }

        pair<int, int> ans = {-100, -100}; 
        for(int d = 0; d <= 9; d++){
            int sum_o = 0, sum_e = 0;
            for(int i = 0; i < sz(s); i++){
                if(!(i == 0 && d == 0)){
                    int cur_o = sum_o + suf_e[i], cur_e = sum_e + suf_o[i];

                    (i % 2 ? cur_o : cur_e) += d;
                    if(abs(cur_o - cur_e) % 11 == 0) {
                        if(cmp({i, s[i] - '0' - d}, ans)) ans = {i, s[i] - '0' - d};
                    }
                }
                (i % 2 ? sum_o : sum_e) += s[i] - '0';
            }

            (sz(s) % 2 ? sum_o : sum_e) += d;
            if(abs(sum_o - sum_e) % 11 == 0) {
                if(cmp({sz(s), d}, ans)) ans = {sz(s), d};
            }
        }

        s.insert(s.begin() + ans.first, char(ans.first != sz(s) ? s[ans.first] - ans.second : ans.second + '0'));
        cout << s << endl;
    }
}