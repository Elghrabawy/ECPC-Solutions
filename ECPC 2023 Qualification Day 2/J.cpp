#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
}

class SegmentTree{
private:
    vector<int> tree;
    int skip = 0; // depentent on merge (sum => 0, min => OO, max => -OO)
    int sz;

    int merge(int a, int b){ return (a + b); }

    int update(int l, int r, int node, int idx, int val){
        if (l == r)
            return tree[node] = val;
        if (idx <= ((r + l) >> 1))
            return tree[node] = merge(update(l, ((r + l) >> 1), node * 2 + 1, idx, val), tree[node * 2 + 2]);
        else
            return tree[node] = merge(tree[node * 2 + 1], update(((r + l) >> 1) + 1, r, node * 2 + 2, idx, val));
    }

    int query(int l, int r, int node, int tl, int tr){
        if (tl > r || tr < l) return skip;
        if (l >= tl && r <= tr) return tree[node];

        return merge(query(l, ((r + l) >> 1), node * 2 + 1, tl, tr), query(((r + l) >> 1) + 1, r, node * 2 + 2, tl, tr));
    }

public:
    SegmentTree(int n){
        sz = 1;
        while (sz <= n) sz *= 2;
        tree = vector<int>(2 * sz, skip);
    }

    void update(int idx, int val) {
        update(0, sz - 1, 0, idx, val);
    }

    int query(int l, int r){
        return query(0, sz - 1, 0, l, r);
    }
};

SegmentTree st(1e5 + 1);
const int N = 100005;
const int Q = 100005;
const int SQ = 318;

struct query
{
    int l, r, x, z, q_idx, block_idx;
    query() {}
    query(int _l, int _r, int _q_idx, int _x, int _z)
    {
        l = _l - 1, r = _r - 1, q_idx = _q_idx, x = _x, z = _z;
        block_idx = _l / SQ;
    }
    bool operator<(const query &y) const
    {
        if (block_idx != y.block_idx)
        {
            return block_idx < y.block_idx;
        }
        return r < y.r;
    }
};

int n, q, v[N], res = 0, q_ans[Q], f[N], ff[N];
int mx = 0;
query queries[Q];
set<int> s;
const int M = 1000002;
int mp[M], mp2[M];
void add(int i){
    mp[mp2[v[i]]]--;

    if(mp[mp2[v[i]]] == 0){
        st.update(mp2[v[i]], 0);
    }

    mp2[v[i]]++;
    mp[mp2[v[i]]]++;
    if(mp[mp2[v[i]]]){
        st.update(mp2[v[i]], 1);
    }
}
void remove(int i){
    mp[mp2[v[i]]]--;
    
    if(mp[mp2[v[i]]] == 0){
        st.update(mp2[v[i]], 0);
    }
    mp2[v[i]]--;
    mp[mp2[v[i]]]++;
    if(mp[mp2[v[i]]]){
        st.update(mp2[v[i]], 1);
    }
}
void mo_process(){
    sort(queries, queries + q);
    int l = 1, r = 0;
    for (int i = 0; i < q; i++){
        while (r < queries[i].r) add(++r);
        while (r > queries[i].r) remove(r--);
        while (l < queries[i].l) remove(l++);
        while (l > queries[i].l) add(--l);

        if(st.query(queries[i].x, queries[i].z) ==  queries[i].z - queries[i].x + 1){
            q_ans[queries[i].q_idx] = 1;
        }
        else{
            q_ans[queries[i].q_idx] = 0;
        }
    }
}


signed main(){
    IO();

    int t = 1; // cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; i++) cin >> v[i];

        cin >> q;
        for (int i = 0; i < q; i++){
            int l, r, x, z;
            cin >> l >> r >> x >> z;
            queries[i] = query(l, r, i, x, z);
        }
        mo_process();

        for (int i = 0; i < q; i++){
            cout << ((q_ans[i] == 1) ? "YES" : "NO") << endl;
        }
    }
}