#include <bits/stdc++.h>
using namespace std;

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

int cnt_avl(int l, int k){
    if(l == k) return 1;
    else{
        return ((l + 1) / (k + 1));
    }
}

int main(){
    IO();
    int L, n, k; cin >> L >> n >> k;
    int q; cin >> q;

    set <int> blocks;
    blocks.insert(0);
    blocks.insert(L + 1);

    int availables = cnt_avl(L, k);
    
    int ans = -1;

    for(int i = 0; i < q; i++){
        
        int x; cin >> x;
        if(blocks.find(x) != blocks.end()) continue;

        auto it = blocks.upper_bound(x);
        auto l_it = it, r_it = it; l_it--;

        int cur_l = *r_it - *l_it - 1;

        availables -= cnt_avl(cur_l, k);
        
        int avl_l = cnt_avl(x - *l_it - 1, k);
        int avl_r = cnt_avl(*r_it - x - 1, k);

        availables += avl_l + avl_r;

        blocks.insert(x);

        if(availables < n){
            ans = i + 1;
            break;
        }
        
    }
    cout << ans << endl;
}
