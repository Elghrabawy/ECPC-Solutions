#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type,
                         less_equal<T>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;

#define ll long long

struct ordered__set
{
    ordered_set<ll> se;
    void erase(ll val) {
        if (se.size() == 0 ||
            *se.find_by_order(se.size() - 1) < val ||
            *se.lower_bound(val - 1) != val) return;
        se.erase(se.lower_bound(--val));
    }

    int lw_bound(ll val)  { // return index -> (if found), -1 -> (if no valid idx);
        if ( se.size() == 0 || *se.find_by_order(se.size() - 1) < val)
            return -1;
        return se.order_of_key(*se.lower_bound(--val));
    }

    void insert(ll val) { se.insert(val); }
    ll operator[](int idx) { return *se.find_by_order(idx); }
    int size() { return se.size(); }

    int cnt_greater(ll val){
        ll ret = lw_bound(val + 1);
        return (ret != -1 ? (size() - ret) : 0);
    }
    int cnt_less(ll val){
        ll ret = lw_bound(val);
        return (ret != -1 ? ret : size());
    }
};

int n;
string s;

void change(ll i, char newC, ll &ans, ordered__set st[]){
    for(int c = 'a'; c < s[i]; c++){
        ans -= st[c - 'a'].cnt_greater(i);
    }
    for(int c = 'a'; c < newC; c++){
        ans += st[c - 'a'].cnt_greater(i);
    }
 
    for(int c = s[i] + 1; c <= 'z'; c++){
        ans -= st[c - 'a'].cnt_less(i);
    }
    for(int c = newC + 1; c <= 'z'; c++){
        ans += st[c - 'a'].cnt_less(i);
    }
 
    st[s[i] - 'a'].erase(i);
    st[newC - 'a'].insert(i);
 
    s[i] = newC;
}

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        cin >> n >> s;
    
        ordered__set st[26];
        for(int i = 0; i < n; i++) st[s[i] - 'a'].insert(i);
    
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(char c = 'a'; c < s[i]; c++){
                ans += st[c - 'a'].cnt_greater(i);
            }
        }
        
        ll q; cin >> q;
        while(q--){
            ll query; cin >> query;
            switch (query)
            {
                case 1:{
                    ll i; cin >> i;
                    char newC; cin >> newC;
                    
                    change(i - 1, newC, ans, st);
                    break;
                }
                case 2:{
                    ll l, r; cin >> l >> r;
                    char newC1 = s[l - 1], newC2 = s[r - 1];
    
                    change(l - 1, newC2, ans, st);
                    change(r - 1, newC1, ans, st); 
    
                    break;
                }
                case 3:{
                    cout << ans << endl;
                    break;
                }
            }
        }
    }
}