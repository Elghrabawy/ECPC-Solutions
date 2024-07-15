#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int INF = 1e15, MOD = 1e9 + 7;

struct SegmentTree {
    vector<int> tree;
    int skip = 0;
    int sz;
 
    int merge(int a, int b){ return a + b; }
 
    int update(int l, int r, int node, int idx, int val){
        if(l == r) return tree[node] = val;
        if(idx <= ((r + l) >> 1))
            return tree[node] = merge(update(l, ((r + l) >> 1), node * 2 + 1, idx, val), tree[node * 2 + 2]);
        else
            return tree[node] = merge(tree[node * 2 + 1], update(((r + l) >> 1) + 1, r, node * 2 + 2, idx, val));
    }
    void update(int idx, int val){ update(0, sz - 1, 0, idx, val); }
 
    int query(int l, int r, int node, int tl, int tr){
        if(tl > r || tr < l) return skip;
        if(l >= tl && r <= tr) return tree[node];
        return merge(query(l, ((r + l) >> 1), node * 2 + 1, tl, tr), query(((r + l) >> 1) + 1, r, node * 2 + 2, tl, tr));
    }
    int query(int l, int r){ return query(0, sz - 1, 0, l, r); }
    
    SegmentTree(int n){
        sz = 1;
        while(sz <= n) sz *= 2;
        tree = vector<int> (2 * sz, skip);
    }
    void insert(int el){ update(el, query(el, el) + 1); }
    void erase(int el){ update(el, query(el, el) - 1); }
    int greater_k(int k){ return query(k, 100000); }
};
 
signed main(){
    IO();

    int n, m; cin >> n >> m;
    vector<int> c(n), cur(n);
    for(auto &el : c) cin >> el;
 
    SegmentTree st(100001);
 
    while(m--){
        int q; cin >> q;
        switch (q) {
        case 1: {
            int i, x; cin >> i >> x;
            --i;
            if(cur[i] + x <= c[i]){
                st.erase(cur[i]);
                cur[i] += x;
                st.insert(cur[i]);
            }
            break;
        }
        case 2:{
            int i, x; cin >> i >> x;
            --i;
            if(cur[i] - x >= 0){
                st.erase(cur[i]);
                cur[i] -= x;
                st.insert(cur[i]);
            }
            break;
        }
        case 3:{
            int k; cin >> k;
            cout << st.greater_k(k) << endl;
            break;
        }
        }
    }
}
