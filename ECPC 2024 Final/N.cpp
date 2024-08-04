#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

const int N = 2e5 + 5;
 
struct SegmentTree {
    vector<int> tree;
    int skip = LLONG_MAX;
    int sz;
 
    #define mid ((r + l) >> 1)
    #define L node * 2 + 1
    #define R node * 2 + 2
 
    int merge(int a, int b){ return min(a, b); }
 
    int build(int l, int r, int node, vector<int> &a){
        if(l == r){
            if(l < (int)a.size()) return (tree[node] = a[l]);
            return skip;
        }
        return tree[node] = merge(build(l, mid, L, a), build(mid + 1, r, R, a));
    }
 
    int update(int l, int r, int node, int idx, int val){
        if(l == r) return tree[node] = val;
        if(idx <= mid) return tree[node] = merge(update(l, mid, L, idx, val), tree[R]);
        else return tree[node] = merge(tree[L], update(mid + 1, r, R, idx, val));
    }
 
    int query(int l, int r, int node, int tl, int tr){
        if(tl > r || tr < l) return skip;
        if(l >= tl && r <= tr) return tree[node];
        return merge(query(l, mid, L, tl, tr), query(mid + 1, r, R, tl, tr));
    }
    SegmentTree(vector <int> &a){
        int n = (int)a.size(); sz = 1;
        while(sz <= n) sz *= 2;
        tree = vector <int> (2 * sz, skip);
        build(0, sz - 1, 0, a);
    }
    SegmentTree(){}
 
    void update(int idx, int val){
        update(0, sz - 1, 0, idx, val);
    }
 
    int query(int l, int r){
        return query(0, sz - 1, 0, l, r);
    }
    #undef R
    #undef L
    #undef mid
};
 
const int INF = 1e15;
vector<int> val(N, -INF), prf(N);
vector<int> dp(N, -1);
SegmentTree st;

int solve(int i){
    if(i <= 0) return i;
 
    int &ret = dp[i];
    if(~ret) return ret;
 
    int v = st.query(i, i);
    if(v == -INF) ret = -INF;
    else{
        int mn = st.query(v + 1, i);
 
        if(v == mn) ret = mn;
        else ret = solve(mn + 1);
    }
    
    st.update(i, ret);
    return ret;
}

signed main(){
    IO();

    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        prf[i + 1] = prf[i] + a[i];
    }
 
    for(int i = 1; i < n; i++){
        int l = 0, r = i - 1;
        while(l <= r){
            int mid = l + r >> 1;
 
            int sum = prf[i] - prf[mid];
            if(sum >= a[i]){
                val[i] = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
 
    st = SegmentTree(val);
    int ans = 0;

    for(int i = 1; i < n; i++){
        if(solve(i) >= 0) ans += i - solve(i);
    }
    cout << ans << endl;
}
