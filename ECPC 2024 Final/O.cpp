#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

#define int long long

struct Node{
    Node* ch[2];
    int cnt[2];
    Node(){ch[0] = ch[1] = NULL, cnt[0] = cnt[1] = 0;}
};
 
struct BinaryTrie{
    Node* root = new Node();
 
    void insert(int val){
        Node* cur = root;
        for(int i = 63; i >= 0; i--){
            int bit = (val >> i) & 1LL;
            if(cur -> ch[bit] == 0) cur -> ch[bit] = new Node();
            cur -> cnt[bit]++;
            cur = cur -> ch[bit];
        }
    }
 
    void erase(int val, Node* cur, int i = 63){
        if(!cur || i == -1) return;
 
        bool bit = (val >> i) & 1LL;
        erase(val, cur -> ch[bit], i - 1);
        cur -> cnt[bit]--;
 
        if(cur -> cnt[bit] == 0){
            delete cur -> ch[bit];
            cur -> ch[bit] = NULL;
        }
    }
    void erase(int val){ erase(val, root, 63); }
 
    int mxXor(int val){
        Node* cur = root;
        int ret = 0;
 
        for(int i = 63; i >= 0; i--){
            bool bit = (val >> i) & 1LL;
            if(cur -> ch[bit ^ 1]){
                ret |= (1LL << i);
                cur = cur -> ch[bit ^ 1];
            }
            else cur = cur -> ch[bit];
        }
        return ret;
    }
 
    int mnXor(int val){
        Node* cur = root;
        int ret = 0;
 
        for(int i = 63; i >= 0; i--){
            bool bit = (val >> i) & 1LL;
            if(cur -> ch[bit]){
                cur = cur -> ch[bit];
            }
            else{
                ret |= (1LL << i);
                cur = cur -> ch[bit ^ 1];
            }
        }
        return ret;
 
    }
};

const int N = 3e5 + 7;
int n, latency[N], ans[N];
vector<int> adj[N];
BinaryTrie trie;

int dfs(int u, int p){
    ans[u] = trie.mnXor(latency[u]);
    trie.insert(latency[u]);

    for(auto &v : adj[u]){
        if(v == p) continue;
        ans[u] = min(ans[u], dfs(v, u));
    }
    trie.erase(latency[u]);
    return ans[u];
}

signed main(){
    IO();

    cin >> n;
    for(int u = 2; u <= n; u++){
        int p; cin >> p;
        adj[p].push_back(u);
    }
    for(int u = 1; u <= n; u++) cin >> latency[u];

    trie.insert(latency[1]);
    dfs(1, 0);

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << ans[x] << endl;
    }
}
