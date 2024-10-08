#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define ll long long
#define sz(x) (int)x.size()

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

template < typename T = int , int Base = 0 > struct SegmentTree2D {

    struct Node {
        T val;
        Node(T V = 0) : val(V) {}
        Node operator = (const T rhs) {
            val = rhs;
            return *this;
        }
    };

    int rows, cols;
    vector < vector < Node > > tree;
    Node DEFAULT;
    #define LEFT(idx) (idx << 1)
    #define RIGHT(idx) ((idx << 1) | 1)
    #define VAL val
    
    SegmentTree2D(int n = 0, int m = 0){
        rows = 1, cols = 1, DEFAULT = 0;
        while(rows < n) rows *= 2;
        while(cols < m) cols *= 2;
        tree = vector < vector < Node > > (2 * rows, vector < Node > (2 * cols, DEFAULT));
    }

    SegmentTree2D(int n, int m, const vector < vector < T > >& nums){
        rows = 1, cols = 1, DEFAULT = 0;
        while(rows < n) rows *= 2;
        while(cols < m) cols *= 2;
        tree = vector < vector < Node > > (2 * rows, vector < Node > (2 * cols, DEFAULT));
        build(nums);
    }

    // Main operation to do
    Node operation(const Node& a, const Node& b){
        return Node(gcd(a.val, b.val));
    }

    // build the current row
    void build_y(int vx, int lx, int rx, int vy, int ly, int ry, const vector < vector < T > > &vec) {
        if(Base ? lx >= sz(vec) : lx > sz(vec)) return; // check rows size
        if(Base ? ly >= sz(vec[0]) : ly > sz(vec[0])) return; // check columns size
        if (ly == ry) {
            if (lx == rx) tree[vx][vy] = Node(vec[lx - !Base][ly - !Base]);
            else tree[vx][vy] = operation(tree[LEFT(vx)][vy], tree[RIGHT(vx)][vy]);
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, LEFT(vy), ly, my, vec);
            build_y(vx, lx, rx, RIGHT(vy), my + 1, ry, vec);
            tree[vx][vy] = operation(tree[vx][LEFT(vy)], tree[vx][RIGHT(vy)]);
        }
    }

    // build the tree row by row
    void build_x(int vx, int lx, int rx, const vector < vector < T > > &vec) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(LEFT(vx), lx, mx, vec);
            build_x(RIGHT(vx), mx + 1, rx, vec);
        }
        build_y(vx, lx, rx, 1, 1, cols, vec);
    }
    
    // build the tree
    void build(const vector < vector < T > > &vec) {
        build_x(1, 1, rows, vec);
    }

    // query the current row
    Node query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) return DEFAULT;
        if (ly == tly && try_ == ry) return tree[vx][vy];
        int tmy = (tly + try_) / 2;
        return operation(query_y(vx, LEFT(vy), tly, tmy, ly, min(ry, tmy)), query_y(vx, RIGHT(vy), tmy + 1, try_, max(ly, tmy + 1), ry));
    }

    // query the tree row by row
    Node query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx) return DEFAULT;
        if (lx == tlx && trx == rx) return query_y(vx, 1, 1, cols, ly, ry);
        int tmx = (tlx + trx) / 2;
        return operation(query_x(LEFT(vx), tlx, tmx, lx, min(rx, tmx), ly, ry), query_x(RIGHT(vx), tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }

    // query the tree
    T query(int lx, int rx, int ly, int ry) {
        return query_x(1, 1, rows, lx, rx, ly, ry).VAL;
    }

    // update the current row
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, T val) {
        if (ly == ry) {
            if (lx == rx) tree[vx][vy] = Node(val);
            else tree[vx][vy] = operation(tree[LEFT(vx)][vy], tree[RIGHT(vx)][vy]);
        } else {
            int my = (ly + ry) / 2;
            if (y <= my) update_y(vx, lx, rx, LEFT(vy), ly, my, x, y, val);
            else update_y(vx, lx, rx, RIGHT(vy), my + 1, ry, x, y, val);
            tree[vx][vy] = operation(tree[vx][LEFT(vy)], tree[vx][RIGHT(vy)]);
        }
    }

    // update the tree row by row
    void update_x(int vx, int lx, int rx, int x, int y, T val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) update_x(LEFT(vx), lx, mx, x, y, val);
            else update_x(RIGHT(vx), mx + 1, rx, x, y, val);
        }
        update_y(vx, lx, rx, 1, 1, cols, x, y, val);
    }

    // update the tree
    void update(int x, int y, T val) {
        update_x(1, 1, rows, x, y, val);
    }

    // get the value of a cell
    T get(int x, int y) {
        return query(x, x, y, y);
    }

    #undef LEFT
    #undef RIGHT
    #undef VAL
};

const int M = 1e9 + 7;

signed main(){
    IO();

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(auto &row : v) for(auto &i : row) cin >> i;

        SegmentTree2D<int> st(n, m, v);

        int q; cin >> q;
        ll ans = 1;
        while(q--){
            int x, y, k; cin >> x >> y >> k;
            ans = ((ans % M) * (st.query(x, x + k - 1, y, y + k - 1) % M)) % M;
            ans %= M;
        }
        cout << ans << endl;
    }
}
