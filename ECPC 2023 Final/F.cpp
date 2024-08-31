#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

struct SegmentTree {
    vector<int> tree;
    int skip = INT32_MAX, sz;
 
    int merge(int a, int b){ return min(a, b); }
 
    void update(int l, int r, int node, int tl, int tr, int val){
        if(l > tr || r < tl) return;
 
        if(l >= tl && r <= tr){
            tree[node] = merge(tree[node], val);
            return;
        }
        
        update(l, ((r + l) >> 1), (node * 2 + 1), tl, tr, val);
        update(((r + l) >> 1) + 1, r, (node * 2 + 2), tl, tr, val);
    }
 
    int query(int l, int r, int node, int idx){
        if(l == r) return tree[node];
 
        if(idx <= ((r + l) >> 1))
            return merge(query(l, ((r + l) >> 1), (node * 2 + 1), idx), tree[node]);
        else
            return merge(query(((r + l) >> 1) + 1, r, (node * 2 + 2), idx), tree[node]);
    }
 
    SegmentTree(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        tree = vector <int> (sz << 1, skip);
    }
 
    int query(int idx){ return query(0, sz - 1, 0, idx); }
    void update(int l, int r, int val){ update(0, sz - 1, 0, l, r, val); }
};

signed main(){
    IO();
    
    int n, k; cin >> n >> k;
    vector<int> a(n), prf(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i], prf[i + 1] = prf[i] + a[i];

    SegmentTree st(n);
    for(int i = 0; i < n; i++){
        int l = i, r = n - 1, ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int sum = prf[mid + 1] - prf[i];
 
            if(sum >= k) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
 
        if(ans != -1){
            int sum = prf[ans + 1] - prf[i];
            int rem = sum - k;
            st.update(i, ans, rem);
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += (st.query(i) >= a[i]);
 
    cout << ans << endl;
}
