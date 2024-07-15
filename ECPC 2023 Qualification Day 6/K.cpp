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

const int INF = 1e15, MOD = 1e9 + 7;
 
int N, X;
vector<int> divisors(int n){
    vector<int> v;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){   
            if(i <= N && (n / i) <= N){
                v.push_back(i);
                if(i * i != n) v.push_back(n / i);
            }
        }
    }
    return v;
}

signed main(){
    IO();

    cin >> N >> X;
    cout << divisors(X).size() << endl;
}
