#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 1, INF = 1e15, MOD = 1e9 + 7;
 
vector<int> factors(int n){
    vector<int> v;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0) 
        {   
            v.push_back(i);
            if(i * i != n) v.push_back(n / i);
        }
    }
    return v;
}
 
int group_money(int n, vector<int> &mul){
    vector<int> facts = factors(n);
    int ret = 0;
    for(auto &f : facts){
        ret += mul[f];
    }
    return ret;
}

signed main(){
    IO();

    int n, q; cin >> n >> q;
    vector<pair<int, int>> student(n + 1); // x group, and money in x before adding
    vector<int> group(n + 1); // money in x group
    vector<int> mul(n + 1);
 
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int s, x; cin >> s >> x;
            student[s] = {x, group_money(x, mul)};
        }
        if(t == 2){
            int x, y; cin >> x >> y;
            mul[x] += y;
        }
        if(t == 3){
            int s; cin >> s;
            vector<int> facs = factors(s);
 
            cout << group_money(student[s].first, mul) - student[s].second << endl;
        }
    }
}
