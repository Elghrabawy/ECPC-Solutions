#include <bits/stdc++.h>
using namespace std;

#define int long long

void IO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin), freopen("../output.txt", "w", stdout);
    #endif
}

int summation(int n){
    return (n * (n + 1)) / 2;
}

signed main(){
    IO();

    int n, d; cin >> n >> d;
    vector<int> a(n);
    for(auto &el : a) cin >> el;
 
    int sum = 0, ans = 0, last = 0;
    for(int i = 0; i < n; i++){
        sum += summation(i + 1 - last) + a[i];
    
        if(sum > d){
            ans++, last = i;
            sum = summation(i + 1 - last) + a[i];
        }
    }
    if(sum) ans++;
    
    cout << ans << endl;
}
