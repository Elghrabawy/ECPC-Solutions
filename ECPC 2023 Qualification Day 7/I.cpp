#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

const int N = 1e5;
int factor[N + 1];
 
void factors(int n){
    for(int i = 1;i * i <= n; i++){
        if(n % i == 0){   
            factor[i]++;
            if(i * i != n) factor[n / i]++;
        }
    }
}

signed main(){
    IO();

    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for(auto &el : a) cin >> el;
    for(auto &el : a) factors(el);
 
    for(int i = N; i >= 1; i--){
        if(factor[i] >= n - k){
            cout << i << endl;
            return 0;
        }
    }
}
