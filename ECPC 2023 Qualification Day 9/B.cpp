#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)x.size()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}
 
signed main(){
    IO();

    int n, m; cin >> n >> m;
    set<int> rsrvd;
    priority_queue <int> avl;
    for(int i = 1; i <= n; i++) avl.push(-i);
 
    while(m--){
        string query; cin >> query;
        if(query == "reserve"){
            if(sz(avl)){
                rsrvd.insert(-avl.top());
                cout << -avl.top() << endl;
                avl.pop();
            }
        }
        else{
            int tbl; cin >> tbl;
            if(rsrvd.count(tbl)){
                rsrvd.erase(tbl);
                avl.push(-tbl);
            }
        }
    }
}
