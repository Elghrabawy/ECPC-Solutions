#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

signed main(){
    IO();

    int n; cin >> n;
    vector<int> a(n); 
    map<int, int> idx;
    ordered_set<int> os;
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        pq.push(a[i]), idx[a[i]] = i, os.insert(i);
    }

    while(!pq.empty()){
        int mx = pq.top(); pq.pop();
        cout << ((os.order_of_key(idx[mx]) % 2) ? "Rashida" : "Bakkar") << endl;
        os.erase(os.lower_bound(--idx[mx]));
    }     
}
